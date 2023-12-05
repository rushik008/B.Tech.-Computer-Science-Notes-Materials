#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define SHM_KEY 0x12345
#define SEM_KEY 0x54321
#define MAX_TRIES 20

struct shmseg {
   int cntr;
   int write_complete;
   int read_complete;
};
void shared_memory_cntr_increment(int, struct shmseg*, int);
void remove_semaphore();

int main(int argc, char *argv[]) {
   int shmid;
   struct shmseg *shmp;
   char *bufptr;
   int total_count;
   int sleep_time;
   pid_t pid;
   if (argc != 2)
   total_count = 10000;
   else {
      total_count = atoi(argv[1]);
      if (total_count < 10000)
      total_count = 10000;
   }
   printf("Total Count is %d\n", total_count);
   shmid = shmget(SHM_KEY, sizeof(struct shmseg), 0644|IPC_CREAT);
   
   if (shmid == -1) {
      perror("Shared memory");
      return 1;
   }
   // Attach to the segment to get a pointer to it.
   shmp = shmat(shmid, NULL, 0);
   
   if (shmp == (void *) -1) {
      perror("Shared memory attach: ");
      return 1;
   }
   shmp->cntr = 0;
   pid = fork();
   
   /* Parent Process - Writing Once */
   if (pid > 0) {
      shared_memory_cntr_increment(pid, shmp, total_count);
   } else if (pid == 0) {
      shared_memory_cntr_increment(pid, shmp, total_count);
      return 0;
   } else {
      perror("Fork Failure\n");
      return 1;
   }
   while (shmp->read_complete != 1)
   sleep(1);
   
   if (shmdt(shmp) == -1) {
      perror("shmdt");
      return 1;
   }
   
   if (shmctl(shmid, IPC_RMID, 0) == -1) {
      perror("shmctl");
      return 1;
   }
   printf("Writing Process: Complete\n");
   remove_semaphore();
   return 0;
}

/* Increment the counter of shared memory by total_count in steps of 1 */
void shared_memory_cntr_increment(int pid, struct shmseg *shmp, int total_count) {
   int cntr;
   int numtimes;
   int sleep_time;
   int semid;
   struct sembuf sem_buf;
   struct semid_ds buf;
   int tries;
   int retval;
   semid = semget(SEM_KEY, 1, IPC_CREAT | IPC_EXCL | 0666);
   //printf("errno is %d and semid is %d\n", errno, semid);
   
   /* Got the semaphore */
   if (semid >= 0) {
      printf("First Process\n");
      sem_buf.sem_op = 1;
      sem_buf.sem_flg = 0;
      sem_buf.sem_num = 0;
      retval = semop(semid, &sem_buf, 1);
      if (retval == -1) {
         perror("Semaphore Operation: ");
         return;
      }
   } else if (errno == EEXIST) { // Already other process got it
      int ready = 0;
      printf("Second Process\n");
      semid = semget(SEM_KEY, 1, 0);
      if (semid < 0) {
         perror("Semaphore GET: ");
         return;
      }
      
      /* Waiting for the resource */
      sem_buf.sem_num = 0;
      sem_buf.sem_op = 0;
      sem_buf.sem_flg = SEM_UNDO;
      retval = semop(semid, &sem_buf, 1);
      if (retval == -1) {
         perror("Semaphore Locked: ");
         return;
      }
   }
   sem_buf.sem_num = 0;
   sem_buf.sem_op = -1; /* Allocating the resources */
   sem_buf.sem_flg = SEM_UNDO;
   retval = semop(semid, &sem_buf, 1);
   
   if (retval == -1) {
      perror("Semaphore Locked: ");
      return;
   }
   cntr = shmp->cntr;
   shmp->write_complete = 0;
   if (pid == 0)
   printf("SHM_WRITE: CHILD: Now writing\n");
   else if (pid > 0)
   printf("SHM_WRITE: PARENT: Now writing\n");
   //printf("SHM_CNTR is %d\n", shmp->cntr);
   
   /* Increment the counter in shared memory by total_count in steps of 1 */
   for (numtimes = 0; numtimes < total_count; numtimes++) {
      cntr += 1;
      shmp->cntr = cntr;
      /* Sleeping for a second for every thousand */
      sleep_time = cntr % 1000;
      if (sleep_time == 0)
      sleep(1);
   }
   shmp->write_complete = 1;
   sem_buf.sem_op = 1; /* Releasing the resource */
   retval = semop(semid, &sem_buf, 1);
   
   if (retval == -1) {
      perror("Semaphore Locked\n");
      return;
   }
   
   if (pid == 0)
      printf("SHM_WRITE: CHILD: Writing Done\n");
      else if (pid > 0)
      printf("SHM_WRITE: PARENT: Writing Done\n");
      return;
}
   
void remove_semaphore() {
   int semid;
   int retval;
   semid = semget(SEM_KEY, 1, 0);
      if (semid < 0) {
         perror("Remove Semaphore: Semaphore GET: ");
         return;
      }
   retval = semctl(semid, 0, IPC_RMID);
   if (retval == -1) {
      perror("Remove Semaphore: Semaphore CTL: ");
      return;
   }
   return;
}
