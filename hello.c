#include<omp.h>
#include<stdio.h>
void main()
{
  omp_set_num_threads(3);

  #pragma omp parallel
{
     printf("hello world- thread no %d\n",omp_get_thread_num());
}
} 
