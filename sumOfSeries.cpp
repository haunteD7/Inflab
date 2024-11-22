#include <math.h>

double sumOfSeries(double x, double min_epsilon, double* epsilon_ptr, int* n_ptr) {
  bool enough_precision = false;

  double sum = 0;
  int n = 0;
  double summand = 0;
  
  for (; !enough_precision; n++) {
    summand = 1 / pow(x, n);
    sum += summand;

    if(min_epsilon >= summand) enough_precision = true;
  }
  *epsilon_ptr = summand;
  *n_ptr = n;

  return sum;
}
