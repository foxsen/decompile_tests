#include <bits/stdc++.h>
using namespace std;
vector<int> a(27);
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    char r;
    cin >> r;
    a[r - 64]++;
  }
  int res = 1e7;
  for (int i = 1; i <= k; i++) {
    res = min(a[i], res);
  }
  cout << res * k;
}
