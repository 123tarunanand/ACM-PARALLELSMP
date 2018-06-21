#include <stdio.h>
#include <omp.h>

int main() {
	//int read,writ,count=0,val=0;
	int val = 0;
	printf("4 readers, 4 writers\n");
	omp_set_num_threads(8);

	omp_lock_t writeLock,readLock;
	omp_init_lock(&writeLock);
	omp_init_lock(&readLock);
  
	#pragma omp parallel
	{
		if(omp_get_thread_num() <= 3) {
		
			int i = 6;
			while(i--) {
				omp_set_lock(&readLock);
		
				omp_set_lock(&writeLock);
				
				printf("value read from thread %d is : %d\n",omp_get_thread_num(),val);
				
				omp_unset_lock(&readLock);
				omp_set_lock(&readLock);

				omp_unset_lock(&writeLock);
				omp_unset_lock(&readLock);
			}
		}
		else {
			int i = 6;
			while(i--) {
				omp_set_lock(&writeLock);
				val ++;
				omp_unset_lock(&writeLock);
			}
		}
	}
}