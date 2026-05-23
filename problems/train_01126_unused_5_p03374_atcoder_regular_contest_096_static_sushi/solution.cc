#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
ll d[N], v[N];
ll Lm[N], Rm[N];

int main() {
  int n;
  ll C;
  cin >> n >> C;
  for(int i = 1; i <= n; ++i) {
    scanf("%lld%lld", &d[i], &v[i]);
  }  
  ll ans = 0, qz = 0;
  for(int i = 1; i <= n; ++i) {
    qz += v[i];
    Lm[i] = max(Lm[i - 1], qz - d[i]);
  }
  qz = 0;
  for(int i = n; i >= 1; --i) {
    qz += v[i];
    Rm[i] = max(Rm[i + 1], qz - (C - d[i]));
  }
  ans = max(ans, max(Lm[n], Rm[1]));
  qz = 0;
  for(int i = 1; i <= n; ++i) {
    qz += v[i];
    ans = max(ans, qz - d[i] * 2 + Rm[i + 1]);
  }
  qz = 0;
  for(int i = n; i >= 1; --i) {
    qz += v[i];
    ans = max(ans, qz - (C - d[i]) * 2 + Lm[i - 1]);
  }
  printf("%lld\n", ans);
  return 0;
}
/*
3 20
2 80
9 120
16 1
*/