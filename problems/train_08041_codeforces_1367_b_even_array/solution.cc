#include <bits/stdc++.h>
using namespace std;
using ill = long long;
void solve() {
  int tct;
  cin >> tct;
  for (int tcc = 1; tcc <= tct; ++tcc) {
    int n;
    cin >> n;
    int cnt0 = 0, cntNM0 = 0;
    vector<int> a(n, 0);
    for (int i = 0; i <= n - 1; ++i) {
      cin >> a[i];
      a[i] %= 2;
      if (a[i] == 0) {
        ++cnt0;
        if (i % 2 == 1) ++cntNM0;
      }
    }
    if (cnt0 != n / 2 + n % 2) {
      cout << "-1\n";
    } else {
      cout << cntNM0 << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  solve();
  cout.flush();
  return 0;
}
