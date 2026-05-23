#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
  point(){};
  point(long long x, long long y) : x(x), y(y){};
};
point operator-(const point &p1, const point &p2) {
  return point(p1.x - p2.x, p1.y - p2.y);
}
long long operator*(const point &p1, const point &p2) {
  return p1.x * p2.y - p1.y * p2.x;
}
long long n, m, sum[100010];
point p[200010], s;
int main(int argc, char **argv) {
  cin >> n;
  sum[0] = 0;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + i;
  for (int i = 0; i <= n - 1; i++) {
    cin >> p[i].x >> p[i].y;
    p[i + n] = p[i];
  }
  cin >> m;
  for (int ca = 1; ca <= m; ca++) {
    cin >> s.x >> s.y;
    bool f = true;
    for (int i = 0; i <= n - 1; i++) {
      if ((p[i] - s) * (p[i + 1] - s) >= 0) {
        f = false;
        break;
      }
    }
    if (f == false) {
      cout << "0" << endl;
      continue;
    }
    long long ans = 0;
    for (int i = 0, k = 0; i <= n - 1; i++) {
      while ((p[i] - s) * (p[k] - s) <= 0) k += 1;
      ans += sum[(k - 1) - i - 1];
      ans += sum[(n + i) - k - 1];
    }
    cout << n * (n - 1) * (n - 2) / 6 - ans / 2 << endl;
  }
  return (EXIT_SUCCESS);
}
