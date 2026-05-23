#include <bits/stdc++.h>
using namespace std;
const int Pow = 1000009, mod1 = 999997, mod2 = 88899987, N = 100005,
          M = 1000005, Mod = 1000000007;
int n, m, num1, num2, Hash[M], _hash[M], _sum, x, Ans, Power[M];
map<int, int> Map[mod1 + 5];
inline int Read() {
  int t = 0, f = 1;
  char c = getchar();
  for (; c > 57 || c < 48; c = getchar())
    if (c == '-') f = -1;
  for (; c > 47 && c < 58; c = getchar()) t = (t << 1) + (t << 3) + c - 48;
  return t * f;
}
int main() {
  n = Read(), m = Read();
  num1 = num2 = 1;
  for (int i = 1; i <= n; i++) {
    _sum = Read();
    num1 = 1ll * num1 * Pow % mod1, num2 = 1ll * num2 * Pow % mod2;
    for (int j = 1; j <= _sum; j++) {
      int x = Read();
      _hash[x] = (1ll * _hash[x] + 1ll * num1) % mod1,
      Hash[x] = (1ll * Hash[x] + 1ll * num2) % mod2;
    }
  }
  Ans = 1;
  Power[1] = 1;
  for (int i = 2; i <= m; i++) Power[i] = 1ll * Power[i - 1] * i % Mod;
  for (int i = 1; i <= m; i++) Map[_hash[i]][Hash[i]]++;
  for (int i = 1; i <= m; i++)
    Ans = 1ll * Ans * Power[Map[_hash[i]][Hash[i]]] % Mod,
    Map[_hash[i]][Hash[i]] = 1;
  printf("%d\n", Ans);
}
