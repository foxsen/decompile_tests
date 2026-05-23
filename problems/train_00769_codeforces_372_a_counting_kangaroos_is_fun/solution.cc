#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int n, c = 0;
  cin >> n;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int r = n - 1;
  for (int i = n / 2 - 1; i >= 0; i--) {
    if (2 * v[i] <= v[r]) {
      c++;
      r--;
    }
  }
  cout << n - c;
  return 0;
}
