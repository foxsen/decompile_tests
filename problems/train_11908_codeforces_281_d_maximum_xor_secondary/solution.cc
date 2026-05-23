#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> v) {
  int res = v[0] ^ v[1], n = ((int)(v).size());
  vector<int> st;
  for (register int i = (0); i < (int)(n); ++i) {
    while (!st.empty() && st.back() < v[i]) st.pop_back();
    st.push_back(v[i]);
    if (((int)(st).size()) >= 2)
      res = max(res, st[((int)(st).size()) - 1] ^ st[((int)(st).size()) - 2]);
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (register int i = (0); i < (int)(n); ++i) cin >> v[i];
  int res = solve(v);
  reverse((v).begin(), (v).end());
  cout << max(res, solve(v)) << endl;
  return 0;
}
