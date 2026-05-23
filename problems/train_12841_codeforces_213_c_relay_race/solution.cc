#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long double E = 1e-17;
char ccc;
inline void read(int &n) {
  n = 0;
  while (true) {
    ccc = getchar();
    if (ccc == ' ' || ccc == '\n') break;
    n = n * 10 + ccc - '0';
  }
}
template <typename T>
inline T sqr(T t) {
  return t * t;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  srand(time(NULL));
  cout.precision(15);
  cout << fixed;
  int n;
  cin >> n;
  int ar[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> ar[i][j];
    }
  }
  int dp[2][n + n][n + n];
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = ar[0][0];
  vector<int> vec[n + n];
  vector<pair<long long, long long> > v[n + n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vec[i + j].push_back(ar[i][j]);
      v[i + j].push_back(make_pair(i, j));
    }
  }
  for (int i = 1; i <= (n - 1) * 2; i++) {
    int w = i & 1;
    int q = 1 - w;
    for (int a = 0; a < n + n; a++) {
      for (int b = 0; b < n + n; b++) {
        dp[w][a][b] = -1e9;
      }
    }
    if (vec[i].size() > vec[i - 1].size()) {
      int prev_size = (int)vec[i - 1].size();
      for (int a = 0; a < (int)vec[i].size(); a++) {
        for (int b = 0; b < (int)vec[i].size(); b++) {
          for (int c = max(0, a - 1); c <= min(prev_size - 1, a); c++) {
            for (int d = max(0, b - 1); d <= min(prev_size - 1, b); d++) {
              pair<long long, long long> f = v[i][a], g = v[i][b];
              dp[w][a][b] =
                  max(dp[w][a][b], dp[q][c][d] + ar[f.first][f.second] +
                                       (a != b ? ar[g.first][g.second] : 0));
            }
          }
        }
      }
    } else {
      int prev_size = (int)vec[i - 1].size();
      for (int a = 0; a < (int)vec[i].size(); a++) {
        for (int b = 0; b < (int)vec[i].size(); b++) {
          for (int c = a; c < min(a + 2, prev_size); c++) {
            for (int d = b; d < min(b + 2, prev_size); d++) {
              pair<long long, long long> f = v[i][a], g = v[i][b];
              dp[w][a][b] =
                  max(dp[w][a][b], dp[q][c][d] + ar[f.first][f.second] +
                                       (a != b ? ar[g.first][g.second] : 0));
            }
          }
        }
      }
    }
    if (0)
      for (int i = 0; i < n + n; i++) {
        for (int j = 0; j < n + n; j++) {
          cout << dp[w][i][j] << "\t";
        }
        cout << "\n";
      }
  }
  cout << dp[0][0][0] << "\n";
}
