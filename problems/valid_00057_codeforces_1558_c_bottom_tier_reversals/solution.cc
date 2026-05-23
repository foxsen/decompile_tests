#include <bits/stdc++.h>
using namespace std;
int pos[3005];
int n;
int a[3005];
void doing(int id, vector<int> &ans) {
  ans.push_back(id);
  reverse(a + 1, a + id + 1);
  for (int i = 1; i <= id; ++i) pos[a[i]] = i;
}
void gogo() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i)
    if ((a[i] + i) % 2) {
      cout << -1 << '\n';
      return;
    }
  vector<int> ans;
  for (int i = n; i > 1; i -= 2) {
    doing(pos[i], ans);
    doing(pos[i - 1] - 1, ans);
    doing(pos[i - 1] + 1, ans);
    doing(pos[i], ans);
    doing(i, ans);
  }
  cout << ((int)(ans).size()) << '\n';
  for (int i : ans) cout << i << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen("sol"
            ".inp",
            "r")) {
    freopen(
        "sol"
        ".inp",
        "r", stdin);
    freopen(
        "sol"
        ".out",
        "w", stdout);
  }
  int t;
  cin >> t;
  while (t--) gogo();
}
