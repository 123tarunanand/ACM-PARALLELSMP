#include <stdio.h>
#include <omp.h>
static long num_steps = 100000000;
double step;
int main ()
{
          
          double x, pi, sum = 0.0;
          double start_time, run_time;

          step = 1.0/(double) num_steps;

           omp_set_num_threads(20);
      
          start_time = omp_get_wtime();
          #pragma omp parallel
        {


         int i,t; 
          t=omp_get_thread_num();
        double sum1=0.0; 

          for (i=(t*5000000);i<=((t+1)*5000000); i++)
           {
                  x = (i-0.5)*step;
                  sum1 = sum1 + 4.0/(1.0+x*x);
          }

         sum=sum+sum1; 
        }
          pi = step * sum;
          run_time = omp_get_wtime() - start_time;
          printf("\n pi with %ld steps is %lf in %lf seconds\n ",num_steps,pi,run_time);
}  
