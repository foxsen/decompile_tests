#include <bits/stdc++.h>
using namespace std;
const int M = (int)1e9 + 7;
void fastIO_test(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve(void) {
  long long n;
  long long k;
  cin >> n >> k;
  string s;
  cin >> s;
  bool balanced = true;
  long long q = 2;
  while (q--) {
    for (long long i = 1; i + k - 1 < n; i++) {
      if (s[i - 1] == '1') {
        if (s[i + k - 1] == '0') {
          balanced = false;
          break;
        } else if (s[i + k - 1] == '?')
          s[i + k - 1] = s[i - 1];
      } else if (s[i - 1] == '0') {
        if (s[i + k - 1] == '1') {
          balanced = false;
          break;
        } else if (s[i + k - 1] == '?')
          s[i + k - 1] = s[i - 1];
      } else {
        if (s[i + k - 1] == '1' || s[i + k - 1] == '0') s[i - 1] = s[i + k - 1];
      }
    }
  }
  if (balanced == false) {
    cout << "NO" << '\n';
    return;
  }
  vector<long long> freq(2);
  for (long long i = 0; i < k; i++) {
    if (s[i] == '0')
      freq[0]++;
    else if (s[i] == '1')
      freq[1]++;
  }
  if (freq[0] > k / 2 || freq[1] > k / 2) balanced = false;
  if (balanced == false) {
    cout << "NO" << '\n';
    return;
  }
  for (long long i = 1; i + k - 1 < n; i++) {
    if (s[i - 1] != '?') freq[s[i - 1] - '0']--;
    if (s[i + k - 1] != '?') freq[s[i + k - 1] - '0']++;
    if (freq[0] > k / 2 || freq[1] > k / 2) {
      balanced = false;
      break;
    }
  }
  if (balanced == false) {
    cout << "NO" << '\n';
    return;
  } else {
    cout << "YES" << '\n';
    return;
  }
}
int main() {
  fastIO_test();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
