#include <bits/stdc++.h>
using namespace std;
int m[2][303300];
int *p1, *p2;
int offset = 151500;
int off = 120000;
int resa[303300];
int mod = 1e9 + 7;
void solve(int a, int k, int t) {
  p1 = m[0] + offset;
  p2 = m[1] + offset;
  memset(m, 0, sizeof(m));
  p1[a] = 1;
  for (int i = 0; i < t; i++) {
    if (i == 2) {
      bool f = 0;
    }
    int tmp = 0;
    memset(p2 - offset, 0, sizeof(m[0]));
    for (int j = -off; j < off; j++) {
      p2[j] = tmp;
      tmp = (((tmp - p1[j - k]) % mod + mod) % mod + p1[j + k + 1]) % mod;
    }
    swap(p1, p2);
  }
}
int main() {
  int a, b, k, t;
  cin >> a >> b >> k >> t;
  solve(a, k, t);
  memcpy(resa, p1 - offset, sizeof(m[0]));
  solve(b, k, t);
  int res = 0;
  int tmp = 0;
  for (int i = -off; i < off; i++) {
    tmp = (tmp + p1[i]) % mod;
    res = (res + ((long long)resa[i + offset + 1] * tmp) % mod) % mod;
  }
  printf("%d\n", res);
  return 0;
}
