#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t = 1;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    char M[n][m];
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < m; j++) {
        cin >> M[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      bool wasBest = false;
      for (int j = 0; j < m; ++j) {
        bool isBest = true;
        for (int k = 0; k < n; ++k)
          if (M[k][j] > M[i][j]) isBest = false;
        if (isBest) wasBest = true;
      }
      if (wasBest) ans++;
    }
    cout << ans;
  }
  return 0;
}
