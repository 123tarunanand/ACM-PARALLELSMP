#include<stdio.h>
#include<omp.h>
void main()
{
    int n;
    printf("enter n");
    scanf("%d",&n);
    int a[n][n],b[n][n],c[n][n];
    int i,j,k,sum;
    double start,run;
    printf("enter 1st array");
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);

     printf("enter 2nd array");
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        scanf("%d",&b[i][j]);

       omp_set_num_threads(n);
     
     start=omp_get_wtime();
     #pragma omp parallel
    {
        i=omp_get_thread_num();
          
        for(j=0;j<n;j++)
        {
         sum=0;
         for(k=0;k<n;k++)
             sum+=(a[i][k]*b[k][j]);
        
        c[i][j]=sum;
        }  
      
    }
     printf("\n run time:%lf",omp_get_wtime()-start);
      for(i=0;i<n;i++)
        {
          printf("\n");
          for(j=0;j<n;j++)
            printf("%d ",c[i][j]);
         }
           
}
