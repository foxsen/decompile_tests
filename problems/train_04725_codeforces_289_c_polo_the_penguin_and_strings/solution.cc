#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:96777216")
using namespace std;
const double NOT_FOUND = -1000000000;
const double EPS = 0.00000001;
const double PI = acos(-1.0);
struct point {
  double x, y;
};
point make_point(double a, double b) {
  point c;
  c.x = a;
  c.y = b;
  return c;
}
struct line {
  double A, B, C;
};
line make_line(double a, double b, double c) {
  line p;
  p.A = a;
  p.B = b;
  p.C = c;
  return p;
}
struct circle {
  double R;
  point center;
  vector<double> intersects;
};
circle make_circle(point c, double r) {
  circle C;
  C.R = r;
  C.center = c;
  return C;
}
int main() {
  int N, K;
  cin >> N >> K;
  if (K > N) {
    cout << -1;
    return 0;
  }
  if (K == 1 && N > 1) {
    cout << -1;
    return 0;
  }
  if (K == N) {
    char p = 'a';
    for (int i = 0; i < N; i++) {
      cout << p;
      p++;
    }
    return 0;
  }
  string S;
  for (char c = 'a' + K - 1; c > 'b'; c--) {
    S += c;
    N--;
  }
  if (N % 2) {
    S += "a";
    N--;
  }
  for (int i = 0; i < N; i += 2) S += "ba";
  for (int i = (int)S.length() - 1; i >= 0; i--) cout << S[i];
  return 0;
}
