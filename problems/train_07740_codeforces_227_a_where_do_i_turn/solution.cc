#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
} A, B, C;
double CCW(point A, point B, point C) {
  return (double)(B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}
void Read() {
  scanf("%lf %lf", &A.x, &A.y);
  scanf("%lf %lf", &B.x, &B.y);
  scanf("%lf %lf", &C.x, &C.y);
}
void Solve() {
  double see = CCW(A, B, C);
  if (see > 0)
    printf("LEFT\n");
  else if (see == 0)
    printf("TOWARDS\n");
  else if (see < 0)
    printf("RIGHT\n");
}
int main() {
  Read();
  Solve();
  return 0;
}
