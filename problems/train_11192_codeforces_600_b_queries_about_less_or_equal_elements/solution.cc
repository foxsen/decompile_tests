#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a;
  vector<int> b;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    cin >> x;
    b.push_back(x);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < m; i++) {
    auto it = upper_bound(a.begin(), a.end(), b[i]);
    cout << it - a.begin() << " ";
  }
}
