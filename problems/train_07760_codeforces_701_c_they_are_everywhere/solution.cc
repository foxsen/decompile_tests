#include <bits/stdc++.h>
using namespace std;
int n, Sum = 0;
string s;
set<char> st;
int vis[200];
bool ok(int mid) {
  memset(vis, false, sizeof(vis));
  int sum = 0;
  for (int i = 0; i < mid; i++) {
    if (!vis[s[i]]) sum++;
    vis[s[i]]++;
  }
  if (sum == st.size()) return true;
  int l = 0, r = mid;
  while (r < n) {
    vis[s[l]]--;
    if (!vis[s[l]]) sum--;
    if (!vis[s[r]]) sum++;
    vis[s[r]]++;
    l++;
    r++;
    if (sum == st.size()) return true;
  }
  return false;
}
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    st.insert(s[i]);
  }
  int l = 0, r = n, mid;
  while (l < r) {
    mid = l + (r - l) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << endl;
  return 0;
}
