#include <bits/stdc++.h>
using namespace std;
void shaon() { cerr << endl; }
template <typename T, typename... north>
void shaon(T arg, const north &...rest) {
  cerr << arg << ' ';
  shaon(rest...);
}
const double eps = 1e-10;
bool equalTo(double a, double b) {
  if (abs(a - b) <= eps)
    return true;
  else
    return false;
}
bool notEqual(double a, double b) {
  if (abs(a - b) > eps)
    return true;
  else
    return false;
}
bool lessThan(double a, double b) {
  if (a + eps < b)
    return true;
  else
    return false;
}
bool lessThanEqual(double a, double b) {
  if (a < b + eps)
    return true;
  else
    return false;
}
bool greaterThan(double a, double b) {
  if (a > b + eps)
    return true;
  else
    return false;
}
bool greaterThanEqual(double a, double b) {
  if (a + eps > b)
    return true;
  else
    return false;
}
long long t;
double x, arr[300002];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 3; i <= 300000; i++) {
    double k = (180.0 / i * 1.0);
    arr[i] = k;
  }
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    cin >> x;
    bool bo = 1;
    for (long long w = 3; w <= 300000; w++) {
      long long p = x / arr[w];
      double pk = arr[w] * p * 1.0;
      if (equalTo(pk, x)) {
        if (p <= (w - 2)) {
          bo = 0;
          cout << (long long)w << "\n";
          break;
        }
      }
    }
    if (bo) cout << "-1\n";
  }
  return 0;
}
