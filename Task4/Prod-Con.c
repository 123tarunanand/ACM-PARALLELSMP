# include <omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  omp_lock_t wlock;
  omp_init_lock(&wlock);
  omp_set_num_threads(2);
  int k = 0;
  #pragma omp parallel
  {
    if(omp_get_thread_num()==0)
    {
      int i ;
      for(i=0;i<n;i++)
      {
        omp_set_lock(&wlock);
        a[k++]=rand()%1000;
        printf("%d is gen\n",a[k-1]);
        omp_unset_lock(&wlock);
      }

    }
    else
    {
      int i;
      for(i=0;i<n;i++)
      {
        while(omp_test_lock(&wlock)==1);
        printf("Consumed is %d\n",a[k-1]);
      }

    }
  }
}
