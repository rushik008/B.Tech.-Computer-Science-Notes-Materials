#include <stdio.h>

void implimentBestFit(int blockSize[], int blocks, int processSize[], int proccesses)
{
    // This will store the block id of the allocated block to a process
    int allocation[proccesses];
    int occupied[blocks];
    
    //calculate fragmentation
    int total_mem = 0;
    for(int i=0 ; i<blocks ; i++) {
        total_mem += blockSize[i];
    }


    // initially assigning -1 to all allocation indexes
    // means nothing is allocated currently
    for(int i = 0; i < proccesses; i++){
        allocation[i] = -1;
    }
    
    for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
 
    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i=0; i<proccesses; i++)
    {
        
        int indexPlaced = -1;
        for (int j=0; j<blocks; j++) 
        { 
            if (blockSize[j] >= processSize[i] && !occupied[j])
            {
                // place it at the first block fit to accomodate process
                if (indexPlaced == -1)
                    indexPlaced = j;
                    
                // if any future block is larger than the current block where
                // process is placed, change the block and thus indexPlaced
                else if (blockSize[indexPlaced] < blockSize[j])
                    indexPlaced = j;
            }
        }
 
        // If we were successfully able to find block for the process
        if (indexPlaced != -1)
        {
            // allocate this block j to process p[i]
            allocation[i] = indexPlaced;
            
            // make the status of the block as occupied
            occupied[indexPlaced] = 1;
 
            // Reduce available memory for the block
            blockSize[indexPlaced] -= processSize[i];
        }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < proccesses; i++)
    {
        printf("%d \t\t\t %d \t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

     //calculate fragmentation
    int allocated_mem = 0;

    for (int i=0; i<proccesses ; i++){
        if (allocation[i] != -1){
                allocated_mem += processSize[i];
        }
    }
    printf("\n Total mem =  %d  and allocated memory = %d hence internal fragmentation = %d \n", total_mem, allocated_mem, (total_mem-allocated_mem));
}
 
// Driver code
int main()
{
    int blockSize[] = {5, 4, 3, 6, 7};
    int processSize[] = {1, 3, 5, 3};
    int blocks = sizeof(blockSize)/sizeof(blockSize[0]);
    int proccesses = sizeof(processSize)/sizeof(processSize[0]);
 
    implimentBestFit(blockSize, blocks, processSize, proccesses);
 
    return 0 ;
}
