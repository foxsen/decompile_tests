#include <bits/stdc++.h>
using namespace std;
int w, h, n;
void func(set<int> &s, multiset<int> &sdist, int x) {
  auto it = s.upper_bound(x), it2 = it--;
  sdist.erase(sdist.find(*it2 - *it));
  sdist.insert(x - *it);
  sdist.insert(*it2 - x);
  s.insert(x);
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> w >> h >> n;
  set<int> ver, hor;
  multiset<int> vdist, hdist;
  ver.insert(0);
  ver.insert(h);
  hor.insert(0);
  hor.insert(w);
  vdist.insert(h);
  hdist.insert(w);
  for (int i = 0; i < n; ++i) {
    char c;
    int x;
    cin >> c >> x;
    if (c == 'H')
      func(ver, vdist, x);
    else
      func(hor, hdist, x);
    cout << (long long)(*hdist.rbegin()) * (*vdist.rbegin()) << '\n';
  }
  return 0;
}
