#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
template <typename T>
istream& operator>>(istream& str, vector<T>& vec) {
  for (auto& w : vec) str >> w;
  return str;
}
template <typename T>
ostream& operator<<(ostream& str, vector<T>& vec) {
  for (auto& w : vec) str << w << ' ';
  return str;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vec(n);
    cin >> vec;
    sort(vec.begin(), vec.end());
    int i = 0;
    int ans = 0;
    int cur;
    while (i < n) {
      cur = vec[i];
      int num = 1;
      int maxx = cur;
      ;
      while (num != maxx && i < n - 1) {
        ++i;
        num++;
        maxx = vec[i];
      }
      if (num == maxx) ans++;
      ++i;
    }
    cout << ans << '\n';
  }
}
