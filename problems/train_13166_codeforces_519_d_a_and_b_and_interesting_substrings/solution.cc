#include <bits/stdc++.h>
using namespace std;
int val[26];
unordered_map<long long, int> ht[26];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  for (int i = 0; i < 26; ++i) cin >> val[i];
  string str;
  cin >> str;
  long long cm = 0, ans = 0;
  for (int i = 0; i < ((int)(str).size()); ++i) {
    ans += ht[str[i] - 'a'][cm];
    cm += val[str[i] - 'a'];
    ++ht[str[i] - 'a'][cm];
  }
  cout << ans << '\n';
  return 0;
}
