#include <bits/stdc++.h>
using namespace std;
using ulong = uint64_t;
void solution() {
  int q, n, k;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& ai : a) cin >> ai;
    for (auto& bi : b) cin >> bi;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>{});
    for (int i = 0; i < k; ++i) {
      if (a[i] < b[i])
        swap(a[i], b[i]);
      else
        break;
    }
    cout << accumulate(a.begin(), a.end(), 0) << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solution();
}
