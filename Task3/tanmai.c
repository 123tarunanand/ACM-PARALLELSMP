#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[]) {
  /* code */
  int n;
  printf("enter n: \n"); scanf("%d", &n);
  int a[n][n], b[n][n], c[n][n];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
  printf("\n");
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &b[i][j]);

  omp_set_num_threads(n);
  float start = omp_get_wtime();
  #pragma omp parallel
  {
    int t = omp_get_thread_num();

    int sum = 0;
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        sum += a[t][k] * b[k][j];
      }
      c[t][j] = sum;
      sum = 0;
    }
  }
  printf("\n%fseconds\n\n", omp_get_wtime() - start);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      printf("%d ", c[i][j]);
    printf("\n");
  }
  return 0;
}
