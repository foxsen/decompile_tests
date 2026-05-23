#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
inline void read(int &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = 10 * x + c - '0';
    c = getchar();
  }
  x *= f;
}
void printDouble(double x, int n) {
  cout << fixed << setprecision(n);
  cout << x << endl;
}
struct color {
  int front, back, both;
};
int main() {
  int n, a, b;
  cin >> n;
  map<int, color> m;
  int target = (n % 2 == 0) ? n / 2 : n / 2 + 1;
  for (int i = 1; i <= n; i++) {
    read(a);
    read(b);
    if (a == b)
      m[a].both++;
    else {
      m[a].front++;
      m[b].back++;
    }
  }
  int res(INT_MAX);
  for (auto i : m) {
    a = target - i.second.both - i.second.front;
    if (a <= i.second.back) res = min(a, res);
  }
  cout << (res == INT_MAX ? -1 : max(res, 0));
}
