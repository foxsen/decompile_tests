#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
template <class T>
ostream& operator<<(ostream& os, vector<T>& _) {
  os << '{';
  for (T& x : _) {
    os << x;
    if (&x != &_.back()) os << ',';
  }
  os << '}';
  return os;
}
template <class T, class U>
ostream& operator<<(ostream& os, pair<T, U>& p) {
  return os << '{' << p.first << " " << p.second << '}';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<char> c;
  for (int i = 0; i < k; ++i) {
    char cc;
    cin >> cc;
    c.emplace_back(cc);
  }
  s += '!';
  sort(c.begin(), c.end());
  int64 ans = 0;
  int streak = 0;
  for (int i = 0; i < n + 1; ++i) {
    if (binary_search(c.begin(), c.end(), s[i])) {
      ++streak;
    } else {
      ans += static_cast<int64>(streak) * static_cast<int64>(streak + 1) / 2LL;
      streak = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
