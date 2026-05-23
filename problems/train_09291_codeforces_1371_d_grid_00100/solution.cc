#include <bits/stdc++.h>
using namespace std;
const long long int num = 1e9 + 7;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k, x = 0;
    cin >> n >> k;
    vector<vector<int> > v(n, vector<int>(n, 0));
    if (k % n == 0)
      cout << 0 << "\n";
    else
      cout << 2 << "\n";
    for (int i = 0; i < n && k; i++) {
      for (int j = 0; j < n && k; j++) {
        v[j][(j + x) % n] = 1;
        k--;
      }
      x++;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << v[i][j];
      }
      cout << "\n";
    }
  }
}
