#include <stdio.h>
#include<omp.h>

int main()
{
    int a[20][20]={1}, b[20][20], result[20][20],i, j, k,t;
for(i=0;i<20;i++)
{
	for(j=0;j<20;j++)
	{
		a[i][j]=1;
		b[i][j]=2;
		result[i][j]=0;
	}
}
omp_set_num_threads(5);
#pragma omp parallel
{
t=omp_get_thread_num();   
    for(i=4*t; i<4*(t+1); ++i)
        for(j=0; j<20; ++j)
#pragma omp critical           
{
	for(k=0; k<20; ++k)
            	{
                	result[i][j]+=a[i][k]*b[k][j];
            	}

    	}
}
    printf("\nOutput Matrix:\n");
    	for(i=0; i<20; ++i)
        {
			for(j=0; j<20; ++j)
        
            			printf("%d  ", result[i][j]);
            
                printf("\n");
	}
        
    return 0;
}
