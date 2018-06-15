#include <stdio.h>
#include <omp.h>

int main()
{
  int read,writ,readcount=0,value=0;
  printf("Enter the number of readers\n");
  scanf("%d",&read);
  printf("Enter the number of writers\n");
  scanf("%d",&writ);
  omp_set_num_threads(read+writ);
  omp_lock_t wlock,rlock;
  omp_init_lock(&wlock);
  omp_init_lock(&rlock);
  #pragma omp parallel
  {
    if(omp_get_thread_num()<read)
    {
      int i = 5;
      do
      {
      omp_set_lock(&rlock);
      readcount++;
      if(readcount==0)
      omp_set_lock(&wlock);
      printf("Value read by thread %d is %d\n",omp_get_thread_num()+1,value);
      omp_unset_lock(&rlock);
      omp_set_lock(&rlock);
      readcount--;
      if(readcount==0)
        omp_unset_lock(&wlock);
      omp_unset_lock(&rlock);
    }while(i--);
    }
    else
    {
      int i = 5;
      do {
      omp_set_lock(&wlock);
      value ++;
      //printf("Writer %d has written value %d\n",omp_get_thread_num()-read+1,value);
      omp_unset_lock(&wlock);
    }while(i--);
  }
  }
}
