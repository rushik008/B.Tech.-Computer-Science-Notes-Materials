//Learnprogramo
#include <stdio.h>
int main()
{
int referenceString[10], pageFaults = 0, m, n, s, pages, frames;
printf("\nEnter the number of Pages:\t");
scanf("%d", &pages);
printf("\nEnter reference string values:\n");
for( m = 0; m < pages; m++)
{
   printf("Value No. [%d]:\t", m + 1);
   scanf("%d", &referenceString[m]);
}
printf("\n What are the total number of frames:\t");
{
   scanf("%d", &frames);
}
int temp[frames];
for(m = 0; m < frames; m++)
{
  temp[m] = -1;
}
for(m = 0; m < pages; m++)
{
  s = 0;
  for(n = 0; n < frames; n++)
   {
      if(referenceString[m] == temp[n])
         {
            s++;
            pageFaults--;
         }
   }     
   pageFaults++;
   if((pageFaults <= frames) && (s == 0))
      {
        temp[m] = referenceString[m];
      }   
   else if(s == 0)
      {
        temp[(pageFaults - 1) % frames] = referenceString[m];
      }
      printf("\n");
      for(n = 0; n < frames; n++)
       {     
         printf("%d\t", temp[n]);
       }
} 
printf("\nTotal Page Faults:\t%d\n", pageFaults);
return 0;
}
