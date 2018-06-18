#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

const double M = 1;
const double m = 1;
const double G = 1;

void centralForce(const double x, const double y, double *a) {

  double r = sqrt(x*x + y*y);

  *a = -(G*M*x)/(r*r*r);
  *(a+1) = -(G*M*y)/(r*r*r);
}

double energy(const double x, const double y, const double vx, const double vy) {

  double r = sqrt(x*x + y*y);
  double v_squared = (vx*vx + vy*vy);
  return (-(G*M*m)/r + 0.5*m*v_squared);
}

void euler(double *x, double *v, double *a, const double dt) {

}

void runge2(double *x, double *v, double *a, const double dt) {

  centralForce(*x, *(x+1), a);
  double k1 = dt*(*a);
  double l1 = dt*(*v);
  double j1 = dt*(*(a+1));
  double z1 = dt*(*(v+1));
  centralForce((*x) + dt*v[0], (*(x+1)) + dt*v[1], a);
  double k2 = dt*(*a);
  double l2 = dt*(v[0] + a[0]*dt);
  double j2 = dt*(*(a+1));
  double z2 = dt*(v[1] * a[1]*dt);
  k = 0.5*(k1+k2);
  l = 0.5*(l1+l2);
  j = 0.5*(j1+j2);
  z = 0.5*(j1+j2);
  v[0] = v[0] + l;
  v[1] = v[1] + z;
  a[0] = a[0] + k;
  a[1] = a[1] + j;
}

void runge4(double *x, double *v, double *a, const double dt) {

}


int main() {

  double x[2], v[2];
  double a[2] = {0.0, 0.0};
  double dt, tend;
  int method; // 0: euler, 1:runge_kutta2, others: runge_kutta4

  cerr << "input x0, y0, vx0, vy0, dt, tend, method" << endl;
  cin >> x[0] >> x[1] >> v[0] >> v[1] >> dt >> tend >> method;
  cerr << x[0] << "\t" << x[1] << "\t" << v[0] << "\t" << v[1] << "\t" << dt << "\t"
       << tend << "\t" << method << endl;

  double e0 = energy(x[0], x[1], v[0], v[1]);
  double tnow = 0.0;

  cout << tnow << "\t" << x[0] << "\t" << x[1] << "\t"
       << v[0] << "\t" << v[1] << endl;

  while (tnow < tend) {
    
    if (method == 0) {
      euler(x, v, a, dt);
    } else if (method == 1) {
      runge2(x, v, a, dt);
    } else {
      runge4(x, v, a, dt);
    }

    double e = energy(x[0],x[1], v[0], v[1]);
    tnow += dt;

    cout << tnow << "\t" << x[0] << "\t" << x[1] << "\t"
         << v[0] << "\t" << v[1] << "\t" << a[0] << "\t"
         << a[1] << "\t" << e << "\t" << (e-e0)/e0 << endl;
  }
}
