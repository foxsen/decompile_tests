#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
const int base = 1e9 + 7;
int n, m;
char s[maxn], t[maxn];
int nxt[maxn][2];
int f[maxn][maxn][maxn];
void Input() {
  cin >> n;
  cin >> (s + 1);
  m = strlen(s + 1);
}
int CalcNxt(char *P, char *B, int len) {
  bool bl;
  for (int i = (len); i >= (0); --i) {
    bl = true;
    for (int j = (1); j <= (i); ++j)
      if (P[j] != B[len - i + j]) {
        bl = false;
        break;
      }
    if (bl) return i;
  }
  return 0;
}
void Init() {
  for (int j = (0); j <= (m - 1); ++j) {
    for (int i = (1); i <= (j); ++i) t[i] = s[i];
    t[j + 1] = '(';
    nxt[j][0] = CalcNxt(s, t, j + 1);
    t[j + 1] = ')';
    nxt[j][1] = CalcNxt(s, t, j + 1);
  }
  nxt[m][0] = m;
  nxt[m][1] = m;
}
int calc(int i, int sum, int matched) {
  if (i == 2 * n) return sum == 0 && matched == m;
  if (sum < 0) return 0;
  int &res = f[i][sum][matched];
  if (res != -1) return res;
  res = calc(i + 1, sum + 1, nxt[matched][0]) +
        calc(i + 1, sum - 1, nxt[matched][1]);
  res %= base;
  return res;
}
void Solve() {
  Init();
  memset(f, 255, sizeof(f));
  cout << calc(0, 0, 0) << '\n';
}
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  Input();
  Solve();
  return 0;
}
