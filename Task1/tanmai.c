#include <stdio.h>
#include <omp.h>

int main() {
	omp_set_num_threads(4);
	#pragma omp parallel
	printf("hell world. thread no - %d nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
	
	return 0;
}
