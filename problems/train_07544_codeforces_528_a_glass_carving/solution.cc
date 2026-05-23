#include <bits/stdc++.h>
using namespace std;
signed long long W, H, N;
set<int> XX, YY;
multiset<int> WW, HH;
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> W >> H >> N;
  XX.insert(0);
  XX.insert(W);
  YY.insert(0);
  YY.insert(H);
  WW.insert(W);
  HH.insert(H);
  for (i = 0; i < N; i++) {
    cin >> s >> x;
    set<int>::iterator it;
    if (s[0] == 'V') {
      it = XX.lower_bound(x);
      y = *it;
      it--;
      j = *it;
      WW.erase(WW.lower_bound(y - j));
      WW.insert(y - x);
      WW.insert(x - j);
      XX.insert(x);
    } else {
      it = YY.lower_bound(x);
      y = *it;
      it--;
      j = *it;
      HH.erase(HH.lower_bound(y - j));
      HH.insert(y - x);
      HH.insert(x - j);
      YY.insert(x);
    }
    auto a = WW.rbegin();
    auto b = HH.rbegin();
    cout << 1LL * (*a) * (*b) << endl;
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
