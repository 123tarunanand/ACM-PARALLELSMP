#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    
	int n, k = 0;
    printf("num elements: ");
    scanf("%d",&n);
    
    int a[n];
    omp_set_num_threads(2);
    
    omp_lock_t wlock;
    omp_init_lock(&wlock);
    
	#pragma omp parallel 
	{  
		if(omp_get_thread_num()==0)
		{
			printf("Produceer - \n");
			for(int i = 0; i < n; i++) {
				omp_set_lock(&wlock);
				a[k] = rand()%1000;
				
				printf("\n produced -  %d", a[k]);
				k++;
				omp_unset_lock(&wlock); // allow consumer to consume
			} 
		}          
        
		else {
			printf("\nConsumer :");
			for(int i = 0; i < n;i++) {
				while(omp_test_lock(&wlock) == 1); // waiting for producer
	
				printf("\nconsuming - %d",a[k-1]); 
			}
		}   
	}
    
	omp_destroy_lock(&wlock);
}