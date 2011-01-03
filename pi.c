#include <stdio.h>

main(int argc, char **argv)
{
  int n, i;
  double d, s, x, pi;
  n = atoi(argv[1]);
  d = 1.0/n;
  s = 0.0;
  for (i=1; i<=n; i++){
    x = (i-0.5)*d;
    s += 4.0/(1.0+x*x);
  }
  pi = d*s;
  
  #pragma omp parallel default(shared) private(iam, np)
  {
    #if defined (_OPENMP)
      
    #endif
    printf("Hello from thread %d out of %d\n", iam, np);
  }
  
  
  printf("pi=%.15f\n", pi);
}

