#include <bits/stdc++.h>
const long long LINF = 1e18;
const int INF = 1e9;
const int M = 1e9 + 7;
const double EPS = 1.0e-9;
const double PI = acos(-1.0);
using namespace std;
string s;
char ch[10010];
int ans[10100];
int main() {
  std::ios_base::sync_with_stdio(0);
  cin >> s;
  int len = s.length();
  int pos = 0;
  while (pos < len - 1) {
    if (s[pos] != s[pos + 1]) {
      ans[pos] = 1;
    }
    pos++;
  }
  if (s[len - 1] == 'a') ans[len - 1] = 1;
  for (int i = 0; i < len; i++) cout << ans[i] << " ";
  return 0;
}
