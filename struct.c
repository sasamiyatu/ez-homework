#include <stdio.h>
#include <math.h>

typedef struct {
  double x;
  double y;
} Point;

typedef struct {
  Point p[3];
} Triangle;

double TriangleArea(Triangle t) {
  double x1 = t.p[0].x;
  double x2 = t.p[1].x;
  double y1 = t.p[0].y;
  double y2 = t.p[1].y;

  printf("x1: %f, x2: %f, y1: %f, y2: %f\n", x1, x2, y1, y2);
  double dist1 = ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  dist1 = sqrt(dist1);
  x2 = t.p[2].x;
  y2 = t.p[2].y;
  double dist2 = ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  dist2 = sqrt(dist2);
  x1 = t.p[1].x;
  y1 = t.p[1].y;
  double dist3 = ((x1-x2)*(x1-x2) + (y1-y2)+(y1-y2));
  dist3 = sqrt(dist3);

  double p = (dist1+dist2+dist3)/2;

  return sqrt(p*(p-dist1)*(p-dist2)*(p-dist3));
}

int CheckCongruence(Triangle t1, Triangle t2) {

  double t1_side1 = sqrt(pow(t1.p[0].x - t1.p[1].x, 2) + pow(t1.p[0].y - t1.p[1].y, 2));
  double t1_side2 = sqrt(pow(t1.p[0].x - t1.p[2].x, 2) + pow(t1.p[0].y - t1.p[2].y, 2));
  double t1_side3 = sqrt(pow(t1.p[1].x - t1.p[2].x, 2) + pow(t1.p[1].y - t1.p[2].y, 2));

  double t1_sides[3] = {t1_side1, t1_side2, t1_side3};
  
  double t2_side1 = sqrt(pow(t2.p[0].x - t2.p[1].x, 2) + pow(t2.p[0].y - t2.p[1].y, 2));
  double t2_side2 = sqrt(pow(t2.p[0].x - t2.p[2].x, 2) + pow(t2.p[0].y - t2.p[2].y, 2));
  double t2_side3 = sqrt(pow(t2.p[1].x - t2.p[2].x, 2) + pow(t2.p[1].y - t2.p[2].y, 2));

  double t2_sides[3] = {t2_side1, t2_side2, t2_side3};
  if (t1_side1 != t2_side1 && t1_side1 != t2_side2 && t1_side1 != t2_side3) {
    return -1;
  }

  int i = 0;
  int j = 0;

  int equal_sides = 0;
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      if (t1_sides[i] == t2_sides[j]) {
         ++equal_sides;
         break;
      }
    }
  }
  if (equal_sides == 3) {
    return 0;
  } else {
    return -1;
  }
}

int main() {

  Triangle t;
  t.p[0].x = 0;
  t.p[0].y = 0;
  t.p[1].x = 1;
  t.p[1].y = 1;
  t.p[2].x = 0;
  t.p[2].y = -1;

  double area = TriangleArea(t);
  printf("%f\n", area);
}
