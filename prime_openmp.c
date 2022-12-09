#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int main (int argc , char* argv[])
{
  long long num = 0 ;
  int *str;
  int *strcp;

  num = atoll(argv[1]);
  str = (int *)malloc(sizeof(int) * num);
  strcp = (int *)malloc(sizeof(int) * num);
  for (long long i = 0 ; i < num ; i++)
    {
      str[i]=i;
      strcp[i]=0;
    }
#pragma omp parallel for schedule(dynamic)
  for (long long i = 0 ; i < num ; i++)
    {
      if (i < 2)
        {
      str[i]=0;
        }
      else if (i > 2)
    {
      for (long long j = 2 ; j < (long long)pow((double)i,0.5) + 1; j++)
        {
          strcp[i] = str[j];
          if (strcp[i] != 0)
        {
          if((str[i] % strcp[i]) == 0)
            {
              str[i] = 0 ;
              break;
                    }
                }
            }
        }
    }
  for (long long i = 0 ; i < num ; i++)
    {
      if(str[i] != 0)
    {
      printf("%d\n",str[i]);
        }
    }
  free(str);
  free(strcp);
  return 0;
}
