#include <bits/stdc++.h>
using namespace std;
int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string S;
    cin >> S;
    int ans = 0;
    bool used[200010] = {};
    for (int i = 0; i < n; i++) {
      if (used[i]) continue;
      int cnt[26] = {};
      int sum = 0;
      set<int> st;
      for (int j = i; j < n; j += k) {
        used[j] = true;
        used[n - j - 1] = true;
        st.insert(j);
        st.insert(n - j - 1);
      }
      int mx = 0;
      for (auto itr = st.begin(); itr != st.end(); itr++) {
        cnt[S[*itr] - 'a']++;
        mx = max(mx, cnt[S[*itr] - 'a']);
      }
      ans += (int)(st.size()) - mx;
    }
    cout << ans << endl;
  }
  return 0;
}
