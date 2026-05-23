#include <bits/stdc++.h>
using namespace std;

int Lcs(string X, string Y) {
  vector< vector<int> > dp(X.size() + 1, vector<int>(Y.size() + 1));
  X = ' ' + X, Y = ' ' + Y;
  for (int i = 1; i <= X.size() - 1; ++i) {
    for (int j = 1; j <= Y.size() - 1; ++j) {
      if (X[i] == Y[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[X.size() - 1][Y.size() - 1];
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    string X, Y;
    cin >> X >> Y;
    cout << Lcs(X, Y) << endl;
  }
}
