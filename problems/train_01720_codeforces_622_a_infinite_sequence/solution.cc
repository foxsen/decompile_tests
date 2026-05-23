#include <bits/stdc++.h>
using namespace std;
template <typename X>
inline X abs(const X& a) {
  return a < 0 ? -a : a;
}
template <typename X>
inline X sqr(const X& a) {
  return a * a;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  double first = (sqrt(8.0 * n + 1) - 1) / 2;
  int out = (first - floor(first)) * (first + 1);
  if (out == 0)
    cout << (int)first;
  else
    cout << out;
}
