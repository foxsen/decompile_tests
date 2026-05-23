#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int mod = 1000000007;
const int maxn = 2000100;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 5);
  vector<int> left(n + 5, 0), right(n + 5, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] <= a[i - 1]) {
      right[i] = right[i - 1] + 1;
    } else
      right[i] = 1;
  }
  for (int i = n; i > 0; i--) {
    if (a[i] <= a[i + 1]) {
      left[i] = left[i + 1] + 1;
    } else
      left[i] = 1;
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    if (left[l] + right[r] > r - l + 1) {
      cout << "Yes"
           << "\n";
    } else
      cout << "No"
           << "\n";
  }
  return 0;
}
