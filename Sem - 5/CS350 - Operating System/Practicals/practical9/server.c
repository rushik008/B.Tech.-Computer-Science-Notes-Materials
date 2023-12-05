#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SEGMENTSIZE sizeof(sem_t)
#define SEGMENTPERM 0666


extern int errno;


int main(int argc, char** argv)
{
    sem_t* sp;
    int retval;
    int id, err;
    if (argc <= 1) {
        printf("Need shmem id.\n");
        exit(1);
    }


    /* Get id from command line . */
    sscanf(argv[1], "%d", &id);
    printf("Allocated %d \n", id);


    /* Attach the segment . */
    sp = (sem_t*)shmat(id, (void*)0, 0);
    if ((int)sp == -1) {
        perror("shmat()");
        exit(2);
    }


    /* Initialize the semaphore . */
    retval = sem_init(sp, 1, 1);
    if (retval != 0) {
        perror(" Couldn t initialize . ");
        exit(3);
    }


    retval = sem_trywait(sp);
    printf("Did trywait. Returned %d >\n", retval);
    getchar();
    retval = sem_trywait(sp);
    printf("Did trywait . Returned %d >\n", retval);
    getchar();
    retval = sem_trywait(sp);
    printf("Did trywait . Returned %d >\n", retval);
    getchar();
    /* Remove segment . */
    err = shmdt((void*)sp);
    if (err == -1)
        perror("shmdt()");
    return 0;
}
}
