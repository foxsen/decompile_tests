#include <bits/stdc++.h>
using namespace std;
template <typename T>
void sci(T& t) {
  cin >> t;
}
template <typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
  sci(t);
  sci(ts...);
}
int32_t main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  bool ans = 1;
  map<char, char> kek;
  kek['4'] = '6';
  kek['6'] = '4';
  kek['5'] = '9';
  kek['9'] = '5';
  kek['8'] = '0';
  kek['0'] = '8';
  kek['7'] = '7';
  kek['3'] = '3';
  int64_t n = s.length();
  for (int64_t(i) = 0; (i) < (int64_t)(n / 2 + 1); ++(i)) {
    if (s[i] == '1' || s[i] == '2' || kek[s[i]] != s[n - i - 1]) {
      ans = 0;
      break;
    }
  }
  cout << ((ans) ? "Yes" : "No") << '\n';
  return 0;
}
