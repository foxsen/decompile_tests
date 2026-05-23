#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int MAXX = 5010;
int number[MAXX][MAXX], acum[MAXX][MAXX];
string x, y;
int solve() {
  int ret = 0;
  memset(number, 0, sizeof(number));
  memset(acum, 0, sizeof(acum));
  for (int i = 0; i < x.size(); i++) {
    number[i][0] = acum[i][0] = (x[i] == y[0]);
    ret = (ret + number[i][0]) % MOD;
  }
  for (int i = 1; i < y.size(); i++) {
    number[0][i] = acum[0][i] = (y[i] == x[0]);
    acum[0][i] += acum[0][i - 1];
    ret = (ret + number[0][i]) % MOD;
  }
  for (int i = 1; i < x.size(); i++) {
    for (int j = 1; j < y.size(); j++) {
      if (x[i] == y[j]) {
        number[i][j] = (number[i][j] + acum[i - 1][j - 1]) % MOD;
        number[i][j]++;
        number[i][j] %= MOD;
      }
      ret = (ret + number[i][j]) % MOD;
      acum[i][j] = (number[i][j] + acum[i][j - 1]) % MOD;
    }
  }
  return ret;
}
int main() {
  cin >> x >> y;
  cout << solve() << endl;
  return 0;
}
