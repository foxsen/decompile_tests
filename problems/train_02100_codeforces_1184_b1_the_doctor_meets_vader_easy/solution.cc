#include <bits/stdc++.h>
using namespace std;
map<int, bool> mapi;
vector<pair<int, int> > base;
long long mod = 1e9 + 7;
char sl = '\n';
template <class T, class U>
inline void checkmin(T &x, U y) {
  if (y < x) x = y;
}
template <class T, class U>
inline void checkmax(T &x, U y) {
  if (y > x) x = y;
}
int s = 0, b = 0;
bool compare(pair<int, int> &p, int i) { return p.first <= i; }
int main() {
  cin >> s >> b;
  vector<int> space(s);
  base.resize(b);
  vector<int> presum(b + 1);
  for (int i = (0); i < (s); ++i) cin >> space[i];
  for (int i = (0); i < (b); ++i) {
    cin >> base[i].first >> base[i].second;
  }
  sort((base).begin(), (base).end());
  presum[0] = 0;
  for (int i = (0); i < (b); ++i) {
    presum[i + 1] = presum[i] + base[i].second;
  }
  for (int i = (0); i < (s); ++i) {
    int idx = lower_bound((base).begin(), (base).end(), space[i], compare) -
              base.begin();
    cout << presum[idx] << ' ';
  }
  cout << sl;
  return 0;
}
