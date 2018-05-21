#include <stdio.h>
#include <omp.h>

static long num_steps = 100000000;
	
int main ()
{
	double x, pi, FinalSum = 0.0;
	double start_time, run_time;
	double step = 1.0/(double) num_steps;
	
	long parts = num_steps / 4;

	start_time = omp_get_wtime();
	
	omp_set_num_threads(4);
	
	#pragma omp parallel 
	{
		double sum = 0;
		int t = omp_get_thread_num();

		for( long int i = parts * t + 1; i <= parts * (t+1); i++) {
			x = (i - 0.5) * step;
  			sum += 4.0 / (1.0 + x*x);		
		}	
			FinalSum += sum;
	}
	pi = FinalSum * step;

	run_time = omp_get_wtime() - start_time;
	printf("\n pi with %ld steps is %lf in %lf seconds\n ",num_steps,pi,run_time);
	return 0;
}
