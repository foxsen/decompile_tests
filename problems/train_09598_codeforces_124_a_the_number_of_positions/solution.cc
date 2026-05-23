#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << min(n - a, b + 1) << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
