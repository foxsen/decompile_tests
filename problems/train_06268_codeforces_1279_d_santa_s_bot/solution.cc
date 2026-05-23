#include <bits/stdc++.h>
using namespace std;
void my_dbg() { cout << endl; }
template <typename Arg, typename... Args>
void my_dbg(Arg A, Args... B) {
  cout << ' ' << A;
  my_dbg(B...);
}
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 998244353;
const int maxN = 1e6 + 2;
int me(int x, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = (1LL * res * x) % mod;
    x = (1LL * x * x) % mod;
    n >>= 1;
  }
  return res;
}
int mi(int x) { return me(x, mod - 2); }
void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mul(int a, int b) { return (1LL * a * b) % mod; }
int main() {
  int n;
  scanf("%d", &n);
  vi child[n];
  vi freq(maxN, 0);
  for (int i = 0; i < (int)n; i++) {
    int k;
    scanf("%d", &k);
    child[i].resize(k);
    for (int& it : child[i]) scanf("%d", &it);
    for (int it : child[i]) freq[it]++;
  }
  int ans = 0;
  for (int i = 0; i < (int)n; i++) {
    int sz = (int)child[i].size();
    for (int it : child[i]) {
      int t1 = mul(1, mi(n));
      int t2 = mul(1, mi(sz));
      int t3 = mul(freq[it], mi(n));
      add(ans, mul(mul(t1, t2), t3));
    }
  }
  printf("%d\n", (int)(ans));
  return 0;
}
