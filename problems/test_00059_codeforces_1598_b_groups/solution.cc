#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
int a[1005][5];
void solve() {
  int n;
  cin >> n;
  set<int> st, b[5];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) {
        st.insert(j);
        b[j].insert(i);
      }
    }
  if (st.size() <= 1) {
    printf("NO\n");
    return;
  }
  for (int i = 0; i < 5; i++)
    for (int j = i + 1; j < 5; j++) {
      if (b[i].size() + b[j].size() >= n && b[i].size() >= n / 2 &&
          b[j].size() >= n / 2) {
        set<int> temp;
        temp.insert(b[i].begin(), b[i].end());
        temp.insert(b[j].begin(), b[j].end());
        if (temp.size() >= n) {
          printf("YES\n");
          return;
        }
      }
    }
  printf("NO\n");
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
