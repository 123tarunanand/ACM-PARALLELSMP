#include<omp.h>
#include<stdio.h>
void main()
{
   int a[20],b[20],c[20],i,t;
   printf("\n enter elements of 1st array");
    for(i=0;i<20;i++)
        scanf("%d",&a[i]);
   printf("\n enter elements of 2nd array");
     for(i=0;i<20;i++)
         scanf("%d",&b[i]);

   omp_set_num_threads(4);
   #pragma omp parallel
   {
       int j;
       t=omp_get_thread_num();
       for(j=(5*t);j<(5*(t+1));j++)
          c[j]=a[j]+b[j];
   }

    printf("sum of each array element is \n");
    for(i=0;i<20;i++)
      printf("%d ",c[i]);
}
