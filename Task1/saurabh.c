#include <omp.h>
#include <stdio.h>
int main() {
omp_set_num_threads(4);
#pragma omp parallel
printf("Hello World from thread number %d\n", omp_get_thread_num());
}


