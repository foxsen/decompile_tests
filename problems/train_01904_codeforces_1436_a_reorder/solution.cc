#include <bits/stdc++.h>
using namespace std;
int fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}
int main() {
  fast();
  long long int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
      m -= arr[i];
    }
    if (m == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
