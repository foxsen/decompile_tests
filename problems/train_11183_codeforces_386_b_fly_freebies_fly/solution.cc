#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int T;
  cin >> T;
  sort(a.begin(), a.end());
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int k = upper_bound(a.begin(), a.end(), a[i] + T) - a.begin();
    k -= i;
    mx = max(mx, k);
  }
  cout << mx << endl;
}
