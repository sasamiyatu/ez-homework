#include <stdio.h>

#define NUM 2

void euler(double *y, double *ynew, double h);

double nextTimeStep(double t, double h); 

void function(double *y, double *result_array);

int main() {

  double y[NUM];
  y[0] = 1000;
  y[1] = 100;
  double ynew[NUM];
  double t = 0;
  double h = 1.0;

  int i = 0;
  printf("0 %f %f\n", y[0], y[1]);
  for (i = 1; i < 1001; ++i) {
    euler(y, ynew, h);
    printf("%d %f %f\n", i, y[0], y[1]);
  }

  return 0;

}

void euler(double *y, double *ynew, double h) {

  double ptr = y;
  double function_result[NUM];
  function(y, function_result);
  *ptr = *y + h*(function_result[0]);
  ++ptr;
  ++y;
  *ptr = *y + h*(function_result[1]);
  
  
}

double nextTimeStep(double t, double h) {
  return t + h;
}

void function(double *y, double *result_array) {

  double ptr = result_array;
  *ptr = 0.01*(*y) - 0.0001*(*y)*(*(y+1));
  ++ptr;
  *ptr = -0.05*(*(y+1)) + 0.0001*(*y)*(*(y+1));
  
}


