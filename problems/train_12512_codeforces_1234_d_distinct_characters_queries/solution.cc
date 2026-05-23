#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;
const int base = 1e9 + 7;
template <typename T>
void Read(T& x) {
  bool Neg = false;
  char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') Neg = !Neg;
  x = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  if (Neg && x > 0) x = -x;
}
long long power(long long a, long long t) {
  if (t == 1) return a;
  long long c = power(a, t / 2);
  if (t % 2 == 1)
    return ((c * c) % base * a) % base;
  else
    return (c * c) % base;
}
long long a[maxn];
struct BIT {
  vector<long long> g;
  BIT(int n) { g.resize(n + 2); }
  void modify(int x, long long val) {
    for (++x; x < g.size(); x += x & -x) g[x] += val;
  }
  long long sumprefix(int x) {
    long long ans = 0;
    for (++x; x; x -= x & -x) ans += g[x];
    return ans;
  }
  void inc(int x, long long val) { modify(x, val); }
  long long getSum(int L, int H) { return sumprefix(H) - sumprefix(L - 1); }
  void incRange(int L, int H, long long val) {
    modify(L, val);
    modify(H + 1, -val);
  }
  long long get(int x) { return sumprefix(x); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  long long m = s.size();
  vector<BIT> g(27, BIT(m + 2));
  for (int i = 0; i <= m - 1; i++) {
    long long k = s[i] - 'a';
    g[k].modify(i + 1, 1);
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == 1) {
      int y;
      char z;
      cin >> y >> z;
      long long k = z - 'a';
      long long t = s[y - 1] - 'a';
      s[y - 1] = z;
      g[t].modify(y, -1);
      g[k].modify(y, 1);
    } else if (x == 2) {
      int y, z;
      cin >> y >> z;
      long long sum = 0;
      for (int j = 0; j <= 26; j++) {
        long long k = g[j].sumprefix(z) - g[j].sumprefix(y - 1);
        if (k >= 1) {
          sum++;
        }
      }
      cout << sum << "\n";
    }
  }
}
