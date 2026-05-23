#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a < 0) v.push_back(-a);
  }
  sort(v.rbegin(), v.rend());
  int x = 0, y = v.size();
  for (int i = 0; i < min(m, y); i++) x += v[i];
  cout << x;
}
