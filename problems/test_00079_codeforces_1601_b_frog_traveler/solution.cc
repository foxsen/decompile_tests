#include <bits/stdc++.h>
using namespace std;
int a[300500];
int b[300500];
int from[300500];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = (0); i < (n); ++i) cin >> a[i + 1];
  for (int i = (0); i < (n); ++i) cin >> b[i + 1];
  vector<int> v;
  v.push_back(n);
  from[n] = n;
  vector<int> nxt;
  set<int> av;
  for (int i = (0); i < (n); ++i) av.insert(i);
  while (v.size() && !from[0]) {
    for (int x : v) {
      int y = x;
      x += b[x];
      int f = x - a[x];
      if (f <= 0) {
        from[0] = y;
        break;
      }
      auto it = av.lower_bound(f);
      while (it != av.end() && *it < x) {
        from[*it] = y;
        nxt.push_back(*it);
        it = av.erase(it);
      }
    }
    v.clear();
    swap(v, nxt);
  }
  if (!from[0])
    cout << -1 << endl;
  else {
    vector<int> st;
    int p = 0;
    while (p < n) {
      st.push_back(p);
      p = from[p];
    }
    cout << st.size() << endl;
    for (; st.size(); st.pop_back()) cout << st.back() << " ";
    cout << endl;
  }
}
