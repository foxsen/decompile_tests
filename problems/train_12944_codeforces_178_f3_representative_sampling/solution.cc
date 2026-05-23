#include <bits/stdc++.h>
using namespace std;
bool SR(int &x) { return scanf("%d", &x) == 1; }
bool SR(long long &x) { return scanf("%lld", &x) == 1; }
bool SR(double &x) { return scanf("%lf", &x) == 1; }
bool SR(char *s) { return scanf("%s", s) == 1; }
bool RI() { return true; }
template <typename I, typename... T>
bool RI(I &x, T &...tail) {
  return SR(x) && RI(tail...);
}
void SP(const int x) { printf("%d", x); }
void SP(const long long x) { printf("%lld", x); }
void SP(const double x) { printf("%.16lf", x); }
void SP(const char *s) { printf("%s", s); }
void PL() { puts(""); }
template <typename I, typename... T>
void PL(const I x, const T... tail) {
  SP(x);
  if (sizeof...(tail)) putchar(' ');
  PL(tail...);
}
const int maxn = 2e3 + 3;
int n, k;
string s[maxn];
void read() {
  RI(n, k);
  static char in[maxn];
  for (int i = 0; i < int(n); i++) {
    RI(in);
    s[i] = in;
  }
}
int h[maxn];
void build() {
  sort(s, s + n);
  for (int i = (1); i <= int(n - 1); i++) {
    int up = min(((int)(s[i]).size()), ((int)(s[i - 1]).size()));
    while (h[i] < up && s[i][h[i]] == s[i - 1][h[i]]) h[i]++;
  }
}
vector<int> doo(int l, int r) {
  if (l == r) return vector<int>(2, 0);
  int mid = min_element(h + l + 1, h + r + 1) - h;
  vector<int> vl = doo(l, mid - 1), vr = doo(mid, r);
  vector<int> v(r - l + 2, 0);
  for (int i = 0; i < int(((int)(vl).size())); i++)
    for (int j = 0; j < int(((int)(vr).size())); j++)
      v[i + j] = max(v[i + j], vl[i] + vr[j] + h[mid] * i * j);
  return v;
}
void sol() { PL(doo(0, n - 1)[k]); }
int main() {
  read();
  build();
  sol();
  return 0;
}
