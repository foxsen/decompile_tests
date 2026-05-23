#include <bits/stdc++.h>
using namespace std;
long long int f[655360] = {1};
long int n, m;
set<long long int> ss;
void ini() {
  for (int i = 1; i < 655360; i++) f[i] = f[i - 1] * 257 % 1000000007;
}
long long int val(string s) {
  long long int res = 0;
  for (int i = 0; i < s.size(); i++) res = (res * 257 + s[i]) % 1000000007;
  return res;
}
int ans(string s) {
  long long int h = val(s);
  long long int l = s.size();
  for (long int j = 0; j < l; j++) {
    for (long long int k = 'a'; k <= 'c'; k++) {
      if (k == s[j]) continue;
      if (ss.find((((k - s[j]) * f[l - j - 1] + h) % 1000000007 + 1000000007) %
                  1000000007) != ss.end()) {
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  cin >> n >> m;
  ini();
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ss.insert(val(s));
  }
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if (ans(s) == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
