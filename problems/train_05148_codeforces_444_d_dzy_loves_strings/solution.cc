#include <bits/stdc++.h>
using namespace std;
vector<int> V[29 * 27 * 27 * 27];
string S;
int L, Q;
map<pair<string, string>, int> M;
void solve() {
  int i, j, k, l, r, x, y;
  string s, t;
  cin >> S >> Q;
  L = S.size();
  for (i = 0; i < L; i++) {
    S[i] -= 'a' - 1;
    V[S[i]].push_back(i);
    if (i - 1 >= 0) V[S[i - 1] * 27 + S[i]].push_back(i - 1);
    if (i - 2 >= 0)
      V[S[i - 2] * 27 * 27 + S[i - 1] * 27 + S[i]].push_back(i - 2);
    if (i - 3 >= 0)
      V[S[i - 3] * 27 * 27 * 27 + S[i - 2] * 27 * 27 + S[i - 1] * 27 + S[i]]
          .push_back(i - 3);
  }
  while (Q--) {
    cin >> s >> t;
    x = y = 0;
    for (__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
      *it -= 'a' - 1, x = x * 27 + *it;
    for (__typeof(t.begin()) it = t.begin(); it != t.end(); it++)
      *it -= 'a' - 1, y = y * 27 + *it;
    if (M.count(make_pair(s, t)) == 0) {
      if (V[x].empty() || V[y].empty()) {
        cout << -1 << endl;
        continue;
      }
      int ret = 1 << 30;
      vector<int>::iterator si = V[x].begin(), ti = V[y].begin();
      while (si != V[x].end() && ti != V[y].end()) {
        ret = min(ret,
                  (int)(max(*si + s.size(), *ti + t.size()) - min(*si, *ti)));
        if (*si < *ti)
          si++;
        else
          ti++;
      }
      M[make_pair(s, t)] = (ret >= 1 << 30) ? -1 : ret;
    }
    cout << M[make_pair(s, t)] << endl;
  }
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false);
  for (i = 0; i < argc - 1; i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < s.size(); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
