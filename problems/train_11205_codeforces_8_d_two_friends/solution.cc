#include <bits/stdc++.h>
using namespace std;
struct Point {
  long double X, Y;
};
const long double eps = 1e-6;
long double Dist(Point A, Point B) {
  return sqrt((A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y));
}
bool Check(Point A, long double RA, Point B, long double RB, Point C,
           long double RC) {
  if (Dist(A, B) < fabs(RA - RB)) return false;
  long double a = 2 * (A.X - B.X), b = 2 * (A.Y - B.Y);
  long double c =
      (A.X * A.X + A.Y * A.Y - RA * RA) - (B.X * B.X + B.Y * B.Y - RB * RB);
  if (b) {
    long double k = -a / b, t = c / b - A.Y;
    long double _A = k * k + 1, _B = 2 * k * t - 2 * A.X,
                _C = A.X * A.X + t * t - RA * RA;
    long double Tmp = sqrt(fabs(_B * _B - 4 * _A * _C));
    long double X0 = (Tmp - _B) / (_A * 2), X1 = -(Tmp + _B) / (_A * 2);
    long double Y0 = k * X0 + t + A.Y, Y1 = k * X1 + t + A.Y;
    if (Dist(C, (Point){X0, Y0}) <= RC) return true;
    if (Dist(C, (Point){X1, Y1}) <= RC) return true;
  } else {
    long double k = -b / a, t = c / a - A.X;
    long double _A = k * k + 1, _B = 2 * k * t - 2 * A.Y,
                _C = A.Y * A.Y + t * t - RA * RA;
    long double Tmp = sqrt(fabs(_B * _B - 4 * _A * _C));
    long double Y0 = (Tmp - _B) / (_A * 2), Y1 = -(Tmp + _B) / (_A * 2);
    long double X0 = k * Y0 + t + A.X, X1 = k * Y1 + t + A.X;
    if (Dist(C, (Point){X0, Y0}) <= RC) return true;
    if (Dist(C, (Point){X1, Y1}) <= RC) return true;
  }
  return false;
}
bool Cross(Point A, long double RA, Point B, long double RB, Point C,
           long double RC) {
  if (Dist(A, B) > RA + RB + eps) return false;
  if (Dist(B, C) > RB + RC + eps) return false;
  if (Dist(C, A) > RC + RA + eps) return false;
  if (Dist(A, B) < RB - RA && Dist(A, C) < RC - RA) return true;
  if (Dist(B, C) < RC - RB && Dist(B, A) < RA - RB) return true;
  if (Dist(C, A) < RA - RC && Dist(C, B) < RB - RC) return true;
  if (Check(A, RA, B, RB, C, RC)) return true;
  if (Check(B, RB, C, RC, A, RA)) return true;
  if (Check(C, RC, A, RA, B, RB)) return true;
  return false;
}
int main() {
  long double T1, T2;
  Point A, B, C;
  cin >> T1 >> T2 >> A.X >> A.Y >> B.X >> B.Y >> C.X >> C.Y;
  long double AB = Dist(A, B), AC = Dist(A, C), BC = Dist(B, C);
  if (AC + BC <= AB + T2)
    printf("%0.10lf\n", (double)min(AC + BC + T1, AB + T2));
  else {
    long double Left = min(T1, T2), Right = min(AC + T1, AB + T2);
    for (int Time = 0; Time < 1000; Time++) {
      long double Mid = (Left + Right) / 2;
      if (Cross(A, Mid, B, AB + T2 - Mid, C, AC + T1 - Mid))
        Left = Mid;
      else
        Right = Mid;
    }
    printf("%0.10lf\n", (double)(Left + Right) / 2);
  }
  return 0;
}
