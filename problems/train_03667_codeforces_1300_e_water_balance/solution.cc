#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
  int n;
  cin >> n;
  int ar[n], it = n - 1;
  stack<pair<ll, int>> st;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    ll ss = ar[i];
    int c = 1;
    while (st.size() && (st.top().first * c > ss * st.top().second)) {
      ss += st.top().first;
      c += st.top().second;
      st.pop();
    }
    st.push(make_pair(ss, c));
  }
  double ans[n];
  while (st.size()) {
    for (int i = it; i > it - st.top().second; i--) {
      ans[i] = (double)(st.top().first) / (double)(st.top().second);
    }
    it -= st.top().second;
    st.pop();
  }
  for (int i = 0; i < n; i++) {
    cout << setprecision(12) << ans[i] << "\n";
  }
}
