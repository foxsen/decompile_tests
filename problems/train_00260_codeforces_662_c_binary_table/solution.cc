#include <bits/stdc++.h>
const int mod = 1000000007;
const int inf = 1000000009;
const long long INF = 1000000000000000009;
const long long big = 1000000000000000;
const long double eps = 0.0000000001;
using namespace std;
int T[21][100005], C[100005];
long long int DP[(1 << 20)][21];
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      T[i][j] = c - '0';
    }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < n; j++) {
      if (T[j][i]) C[i] += (1 << j);
    }
    DP[C[i]][0]++;
  }
  int wynik = inf;
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i < (1 << n); i++) {
      if (j >= 2) DP[i][j] += (long long int)(j - 2 - n) * DP[i][j - 2];
      for (int k = 0; k < n; k++) DP[i][j] += DP[i ^ (1 << k)][j - 1];
      DP[i][j] /= j;
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    int aktual = 0;
    for (int j = 0; j <= n; j++) aktual += DP[i][j] * min(j, n - j);
    wynik = min(wynik, aktual);
  }
  cout << wynik;
  return 0;
}
