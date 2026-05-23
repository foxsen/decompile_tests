#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> s;
  if (!k) {
    cout << s;
    return 0;
  }
  if (int(s.size()) == 1) {
    cout << 0;
    return 0;
  }
  if (s[0] != '1') {
    s[0] = '1';
    --k;
  }
  for (int i = 1; i < int(s.size()) && k; ++i) {
    if (s[i] == '0') continue;
    s[i] = '0';
    --k;
  }
  cout << s;
  return 0;
}
