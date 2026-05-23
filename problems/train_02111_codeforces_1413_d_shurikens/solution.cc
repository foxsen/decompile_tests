#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, n, m, x;
set<long long> st;
long long res[200009], pos[200009];
vector<long long> q;
int main() {
  cin >> n;
  long long cnt = 0;
  for (i = 1; i <= 2 * n; i++) {
    char t;
    cin >> t;
    if (t == '+')
      st.insert(++cnt), q.push_back(0);
    else {
      cin >> k;
      pos[k] = cnt;
      q.push_back(k);
    }
  }
  for (i = 1; i <= n; i++) {
    auto it = st.upper_bound(pos[i]);
    if (it == st.begin()) return cout << "NO" << '\n', 0;
    it--;
    res[*it] = i;
    st.erase(it);
  }
  st.clear();
  cnt = 0;
  for (auto to : q) {
    if (to == 0) {
      st.insert(res[++cnt]);
    } else {
      if (*st.begin() != to) return cout << "NO" << '\n', 0;
      st.erase(to);
    }
  }
  cout << "YES" << '\n';
  for (i = 1; i <= n; i++) cout << res[i] << ' ';
  cout << '\n';
  exit(0);
}
