#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
void main()
{
    int n,k=0,j=1;
    printf("\n enter n");
    scanf("%d",&n);
    
    int a[n];
    omp_set_num_threads(2);
    
    omp_lock_t wlock;
    omp_init_lock(&wlock);
    
    #pragma omp parallel 
     {
      
           if(omp_get_thread_num()==0)
           {
              int i;
               printf("\ninto thread 0:");
              for(i=0;i<n;i++)
               {
                omp_set_lock(&wlock);
                    a[k++]=rand()%1000;
                   
                 printf("\n production of element %d",a[k-1]);
                 omp_unset_lock(&wlock);
               } 
          }          
        
         else 
          {
             printf("\ninto thread 1:");
	      int i;
               for(i=0;i<n;i++)
              {

                 while(omp_test_lock(&wlock)==1);

                  printf("\nconsumed element %d",a[k-1]); 
              }
           }   
        
      
     }
    omp_destroy_lock(&wlock);
}

B
A
A
    
