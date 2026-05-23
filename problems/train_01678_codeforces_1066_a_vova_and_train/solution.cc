#include <bits/stdc++.h>
using namespace std;
void in() {
  ifstream cin("input.txt");
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
void solution() {}
void out() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int F, u, L, R, ans = 0;
    cin >> F >> u >> L >> R;
    ans = F / u - R / u + (L - 1) / u;
    cout << ans << "\n";
  }
  return 0;
}
