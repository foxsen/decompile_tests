#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int f = 0;
    map<int, int> m;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (i) {
        if (m[a[i]] >= 2 || (m[a[i]] && a[i] != a[i - 1])) f = 1;
      }
      m[a[i]]++;
    }
    if (f)
      cout << "YES";
    else
      cout << "NO";
    cout << '\n';
  }
  return 0;
}
