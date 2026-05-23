#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:640000000")
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
int s[44], x[44];
long long dp[44][2][2][2];
long long dfs(int pos, int tmp, int wasa, int wasb) {
  if (pos < 0) return tmp == 0 && wasa == 0 && wasb == 0;
  long long &res = dp[pos][tmp][wasa][wasb];
  if (res != -1) return res;
  res = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int wa = 0; wa < 2; wa++) {
          for (int wb = 0; wb < 2; wb++) {
            int S = (i + j + k) % 2;
            int TMP = (i + j + k) / 2;
            int X = i ^ j;
            if (tmp != TMP || x[pos] != X || s[pos] != S) continue;
            if ((wa | (i == 1)) != wasa || (wb | (j == 1)) != wasb) continue;
            res += dfs(pos - 1, k, wa, wb);
          }
        }
      }
    }
  }
  return res;
}
int main() {
  memset(dp, -1, sizeof(dp));
  long long S, X;
  cin >> S >> X;
  for (int i = 0; i <= 40; i++) {
    s[i] = S % 2;
    S /= 2;
    x[i] = X % 2;
    X /= 2;
  }
  cout << dfs(40, 0, 1, 1) << endl;
  return 0;
}
