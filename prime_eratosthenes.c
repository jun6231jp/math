#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc , char *argv[])
{
  long long i, j;
  long long num = 0;
  long long sq = 0;
  long long *prime;

  num = atoll(argv[1]);
  sq=(long long)pow((double)num , 0.5);
  prime = (long long *)malloc(sizeof(long long) * num);


  for (i = 0; i < num; i++)
    {
      prime[i] = 1;  
    }
  prime[0] = 0;  

  #pragma omp parallel for private(j) schedule(dynamic)
  for (i = 1; i < sq; i++) {
    if (prime[i] == 1) 
      {
    for (j = (i+1); (i+1) * j <= num; j++)
      {
        prime[(i+1) * j - 1] = 0;
      }
      }
  }

  for (i = 0; i < num; i++)
    if (prime[i] == 1)  
      printf("%d\n", i + 1);

  free(prime);

  return (0);
}
