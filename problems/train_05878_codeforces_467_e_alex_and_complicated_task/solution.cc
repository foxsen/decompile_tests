#include <bits/stdc++.h>
using namespace std;
int a[500005];
map<int, int> pre;
map<int, int> num;
vector<int> ans;
stack<int> st;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      num[a[i]] = 0;
    }
    for (int k = 0; k <= n;) {
      pre.clear();
      int i;
      for (i = k + 1; i <= n; i++) {
        if (pre[a[i]]) {
          for (int j = 0; j <= 1; j++) {
            ans.push_back(pre[a[i]]);
            ans.push_back(a[i]);
          }
          break;
        } else {
          if (num[a[i]] == 0)
            st.push(a[i]);
          else {
            while (!st.empty()) {
              int u = st.top();
              st.pop();
              if (u == a[i]) break;
              pre[u] = a[i];
            }
            st.push(a[i]);
          }
          num[a[i]]++;
          if (num[a[i]] == 4) {
            for (int j = 0; j <= 3; j++) ans.push_back(a[i]);
            break;
          }
        }
      }
      while (!st.empty()) st.pop();
      for (int j = k + 1; j <= i; j++) num[a[j]] = 0;
      k = i;
    }
    printf("%d\n", ans.size());
    for (int u : ans) printf("%d ", u);
    printf("\n");
  }
  return 0;
}
