#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
const int limit = 3e5 + 10;
void solve() {
  string s;
  cin >> s;
  int finally = 0;
  for (char ch : s) {
    if (ch == 'A' || ch == 'C') {
      finally--;
    } else {
      finally++;
    }
  }
  if (finally == 0) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
