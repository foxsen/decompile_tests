#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1e6 + 10;
struct Union_Find {
  int d[SIZE], num[SIZE];
  void init(int n) {
    for (int i = 0; i < (n); ++i) d[i] = i, num[i] = 1;
  }
  int find(int x) {
    int y = x, z = x;
    while (y != d[y]) y = d[y];
    while (x != y) {
      x = d[x];
      d[z] = y;
      z = x;
    }
    return y;
  }
  bool is_root(int x) { return d[x] == x; }
  bool uu(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    if (num[x] > num[y]) swap(x, y);
    num[y] += num[x];
    d[x] = y;
    return 1;
  }
} U;
long long C2(int x) { return x * (x - 1LL) / 2; }
int main() {
  int n, m;
  R(n, m);
  U.init(n);
  for (int i = 0; i < (m); ++i) {
    int x, y;
    R(x, y);
    x--;
    y--;
    U.uu(x, y);
  }
  long long res = 0;
  for (int i = 0; i < (n); ++i) {
    if (U.is_root(i)) res += C2(U.num[i]);
  }
  W(res == m ? "YES" : "NO");
  return 0;
}
