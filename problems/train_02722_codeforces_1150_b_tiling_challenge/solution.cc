#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long i;
  string second[n];
  for (i = 0; i < n; i++) cin >> second[i];
  long long a[n + 2][n + 2];
  long long j;
  for (i = 0; i <= n + 1; i++)
    for (j = 0; j <= n + 1; j++) a[i][j] = 1;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (second[i][j] == '.')
        a[i + 1][j + 1] = 0;
      else
        a[i + 1][j + 1] = 1;
    }
  }
  long long count = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (a[i][j] == 0 && a[i - 1][j] == 0 && a[i][j - 1] == 0 &&
          a[i + 1][j] == 0 && a[i][j + 1] == 0) {
        a[i][j] = 1;
        a[i - 1][j] = 1;
        a[i][j - 1] = 1;
        a[i + 1][j] = 1;
        a[i][j + 1] = 1;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (a[i][j] == 0) {
        count = 1;
        break;
      }
    }
  }
  if (count == 1)
    cout << "NO\n";
  else
    cout << "YES\n";
}
