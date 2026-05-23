#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<long long> > C(n + 1, vector<long long>(n + 1));
  for (int i = 0; i < n + 1; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  cout << C[n][5] + C[n][6] + C[n][7];
  return 0;
}
