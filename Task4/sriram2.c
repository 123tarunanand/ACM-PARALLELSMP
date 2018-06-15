#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
//#include<iomanip.h>
void main()
{
    int k=0;
   
    omp_set_num_threads(7);
    
    omp_lock_t wlock;
    omp_lock_t rlock;
    omp_init_lock(&wlock);
    omp_init_lock(&rlock);    
    #pragma omp parallel 
     {
      
           if(omp_get_thread_num()<4)
           {
               while(omp_test_lock(&rlock)==1);  
                 printf("\n reading element %d from thread %d",k,omp_get_thread_num());
                
          }          
        
         else 
          {
             while(omp_test_lock(&wlock)==1);
                omp_set_lock(&wlock);
                  printf("\n lock set to writer");
                omp_set_lock(&rlock);
                  printf("\n lock set to reader");
                  
                 if(k<10)
			 k++;
		else
                     exit(0);
                
                printf("\n writing element %d from thread %d",k,omp_get_thread_num());
                omp_unset_lock(&rlock);
                 printf("\n reader lock free");
                omp_unset_lock(&wlock);
                printf("\n writer lock free");
             
           }   
        
      
     }
    omp_destroy_lock(&wlock);
}
    



