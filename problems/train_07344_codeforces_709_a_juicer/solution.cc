#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int maxn = 1e6 + 5;
const int maxm = 1e6 + 5;
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
inline int scan(int &a) { return scanf("%d", &a); }
inline int scan(int &a, int &b) { return scanf("%d%d", &a, &b); }
inline int scan(int &a, int &b, int &c) { return scanf("%d%d%d", &a, &b, &c); }
inline int scan(long long &a) { return scanf("lld", &a); }
inline int scan(long long &a, long long &b) { return scanf("lldlld", &a, &b); }
inline int scan(long long &a, long long &b, long long &c) {
  return scanf("lldlldlld", &a, &b, &c);
}
inline int scan(double &a) { return scanf("%lf", &a); }
inline int scan(double &a, double &b) { return scanf("%lf%lf", &a, &b); }
inline int scan(double &a, double &b, double &c) {
  return scanf("%lf%lf%lf", &a, &b, &c);
}
inline int scan(char &a) { return scanf("%c", &a); }
inline int scan(char *a) { return scanf("%s", a); }
template <class T>
inline void mem(T &A, int x) {
  memset(A, x, sizeof(A));
}
template <class T0, class T1>
inline void mem(T0 &A0, T1 &A1, int x) {
  mem(A0, x), mem(A1, x);
}
template <class T0, class T1, class T2>
inline void mem(T0 &A0, T1 &A1, T2 &A2, int x) {
  mem(A0, x), mem(A1, x), mem(A2, x);
}
template <class T0, class T1, class T2, class T3>
inline void mem(T0 &A0, T1 &A1, T2 &A2, T3 &A3, int x) {
  mem(A0, x), mem(A1, x), mem(A2, x), mem(A3, x);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void mem(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, int x) {
  mem(A0, x), mem(A1, x), mem(A2, x), mem(A3, x), mem(A4, x);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void mem(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, int x) {
  mem(A0, x), mem(A1, x), mem(A2, x), mem(A3, x), mem(A4, x), mem(A5, x);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void mem(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6, int x) {
  mem(A0, x), mem(A1, x), mem(A2, x), mem(A3, x), mem(A4, x), mem(A5, x),
      mem(A6, x);
}
template <class T>
inline T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <class T>
inline T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <class T>
inline T min(T a, T b, T c, T d) {
  return min(min(a, b), min(c, d));
}
template <class T>
inline T max(T a, T b, T c, T d) {
  return max(max(a, b), max(c, d));
}
template <class T>
inline T min(T a, T b, T c, T d, T e) {
  return min(min(min(a, b), min(c, d)), e);
}
template <class T>
inline T max(T a, T b, T c, T d, T e) {
  return max(max(max(a, b), max(c, d)), e);
}
int a[maxn];
int main() {
  int n, b, d;
  scan(n, b, d);
  int sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    scan(a[i]);
    if (a[i] > b) continue;
    sum += a[i];
    if (sum > d) sum = 0, ans++;
  }
  printf("%d\n", ans);
  return 0;
}
