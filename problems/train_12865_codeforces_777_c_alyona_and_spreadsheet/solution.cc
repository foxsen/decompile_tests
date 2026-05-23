#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
int main() {
  fast();
  int n, m;
  cin >> n >> m;
  int last[100005] = {0}, c[100005] = {0};
  int mx[100005];
  for (int i = 0; i < n; i++) {
    mx[i] = 0;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      if (x >= last[j])
        c[j]++;
      else
        c[j] = 1;
      last[j] = x;
      mx[i] = max(mx[i], c[j]);
    }
  }
  int k;
  cin >> k;
  while (k--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << (mx[r] >= r - l + 1 ? "Yes" : "No") << endl;
  }
  return 0;
  ;
}
