#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, n, m;
    cin >> a >> b >> n >> m;
    if (a + b < n + m)
      cout << "No";
    else {
      if (a >= m and b >= m)
        cout << "Yes";
      else
        cout << "No";
    }
    cout << "\n";
  }
}
