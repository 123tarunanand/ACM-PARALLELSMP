#include<omp.h>
#include<stdio.h>

int main()
{
   omp_set_num_threads(3);
   #pragma omp parallel
   {
        printf("hello world - thread number %d\n",omp_get_thread_num());
   }
   return 0;
}
