#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, ans;
  int n, maxx = -1, minn = -1;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  if (v[1] - v[0] > v[n - 1] - v[n - 2]) {
    cout << v[n - 1] - v[1];
  } else {
    cout << v[n - 2] - v[0];
  }
}
