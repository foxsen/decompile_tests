#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 300;
int n, cnt[N];
int ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string st;
    cin >> st;
    for (int j = 0; j < st.size(); j++) {
      if (st[j] == '1') cnt[j]++;
    }
  }
  for (int i = 0; i < 10; i++) {
    ans = max(ans, cnt[i]);
  }
  cout << ans << endl;
  cin.get();
  cin.get();
  return 0;
}
