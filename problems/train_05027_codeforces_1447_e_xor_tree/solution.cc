#include <bits/stdc++.h>
using namespace std;
int best(int bit, vector<int> v) {
  if (bit == 0) {
    return v.size();
  }
  vector<int> set, unset;
  for (int i = 0; i < v.size(); i++) {
    if (((1 << bit) & v[i]) > 0)
      set.push_back(v[i]);
    else
      unset.push_back(v[i]);
  }
  int x = set.size();
  int y = unset.size();
  if (x < 2) {
    return x + best(bit - 1, unset);
  }
  if (y < 2) {
    return y + best(bit - 1, set);
  }
  if (x >= 2 && y >= 2) {
    return max(1 + best(bit - 1, set), 1 + best(bit - 1, unset));
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  cout << n - best(30, v) << '\n';
  return 0;
}
