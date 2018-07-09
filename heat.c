#include <iostream>
#include <stdio.h>


using namespace std;

  int main(){

  double  x0 = 0.0;
  double  xe = 4.0;
  double  t0 = 0.0;
  double  te = 1.0;
  double h = 0.50;
  double c = 2.0;

  double k; 
  cerr  << "input k" << endl;
  cin  >> k;

  int n = (xe-x0)/h;
  int nt = (te-t0)/k;
  double r = (c*k)/(h*h);
  cerr  << h << "\t" << k << "\t" << n << "\t" << nt << "\t" << r << endl;

  double z[n+1][nt];

  for( int i=0; i<n; i++){
    z[i][0] = 1;
  }

  for( int j=0; j<nt; j++){
    z[0][j] = 0;
    z[n][j] = 0;
  }


  for(int j = 0; j <(nt-1); j++) {
    for(int i = 1; i < n; i++) {
      z[i][j+1] = r*z[i+1][j] + (1.0-2.0*r)*z[i][j] + r*z[i-1][j];
    }
  }

  for( int j=0; j<nt; j++){
    for( int i=0; i<=n; i++){
      double x = x0 + i*h;
      fprintf( stdout , "%.4lf %.4lf\n", x, z[i][j]);
     }
    fprintf( stdout , "\n\n");
  }

}
