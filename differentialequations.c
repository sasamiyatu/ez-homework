#include <iostream> 
#include <cstdio> 
#include <cmath> 

using namespace std; 

double dydx(const double x, const double y, const double z){ 
   return z; 
 } 

double dzdx(const double x, const double y, const double z) {
   return x*(z-y); 
 } 

int main() { 

   double x0, y0, z0, xe, h; 
   cerr << "input x0, y0, z0, xe, h" << endl; 
   cin >> x0 >> y0 >> z0 >> xe >> h; 
   cerr << x0 << "\t" << y0 << "\t" << z0 << "\t" << xe << "\t" << h << endl; 

   double x = x0; 
   double y = y0; 
   double z = z0; 
   cout << x << "\t" << y << "\t" << z << endl; 
   while (x < xe) { 
     double k1 = h*dydx(x, y, z); 
     double l1 = h*dzdx(x, y, z); 
     double k2 = h*dydx(x+h, y+k1, z+l1); 
     double l2 = h*dzdx(x+h, y+k1, z+l1); 
     double k = (k1+k2)/2.0; 
     double l = (l1+l2)/2.0; 
     // cout << k << "  " << l << "  " << k2 << "  " << l2 << endl;
 
     x = x + h;
     y = y + k; 
     z = z + l; 

    cout << x << "\t" << y << "\t" << z << endl;
   }
}
