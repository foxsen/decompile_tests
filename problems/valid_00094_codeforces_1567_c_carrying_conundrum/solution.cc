#include <bits/stdc++.h>
using namespace std;
const long long N = 300010, M = 11, Mod = 1e9 + 7;
long long n, m, a[N];
long long Dp[M][2][2];
string s;
long long Solve(int i = 0, int Cur = 0, int Nxt = 0) {
  if (i == n) {
    return (Cur == 0 && Nxt == 0);
  }
  long long &Res = Dp[i][Cur][Nxt];
  if (Res != -1) {
    return Res;
  }
  Res = 0;
  for (int j = 0; j <= 9; j++) {
    for (int k = 0; k <= 9; k++) {
      if (j == k) {
        continue;
      }
      int Need = (s[i] - '0');
      int Sum = (Cur + j + k);
      int Rem = (Sum % 10);
      int Cary = (Sum >= 10);
      if (Rem == Need) {
        Res += Solve(i + 1, Nxt, Cary);
      }
    }
  }
  for (int j = 0; j <= 9; j++) {
    int Need = (s[i] - '0');
    int Sum = (Cur + j + j);
    int Rem = (Sum % 10);
    int Cary = (Sum >= 10);
    if (Rem == Need) {
      Res += Solve(i + 1, Nxt, Cary);
    }
  }
  return Res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TT;
  cin >> TT;
  for (int T = 1; T <= TT; T++) {
    cin >> s;
    reverse(s.begin(), s.end());
    n = s.size();
    memset(Dp, -1, sizeof Dp);
    long long Ans = Solve();
    cout << Ans - 2 << endl;
  }
  return 0;
}
