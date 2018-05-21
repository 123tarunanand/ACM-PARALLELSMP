#include<stdio.h>
#include<omp.h>
int main(){
int a[20],b[20],c[20],t;
for(int i=0;i<20;i++)
{a[i]=20;
b[i]=20;}
omp_set_num_threads(4);
#pragma omp parallel 
{
t= omp_get_thread_num();
printf("%d ",t);
for(int i=5*t;i<5*(t+1);i++)
c[i]=a[i]+b[i];
}
for(int i=0;i<20;i++)
printf("%d ",c[i]);
return 0;
}


