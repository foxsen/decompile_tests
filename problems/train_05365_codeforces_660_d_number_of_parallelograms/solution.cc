#include <bits/stdc++.h>
using namespace std;
struct Center {
  int x, y;
  bool _x, _y;
  bool operator==(const Center& a) const {
    return (x == a.x && y == a.y && _x == a._x && _y == a.y);
  }
  bool operator<(const Center& a) const {
    if (x != a.x) return x < a.x;
    if (y != a.y) return y < a.y;
    if (_x != a._x) return _x < a._x;
    return _y < a._y;
  }
  Center() {}
  Center(int x1, int y1, int x2, int y2) {
    x = (x1 + x2) / 2;
    y = (y1 + y2) / 2;
    _x = (x1 + x2) & 1;
    _y = (y1 + y2) & 1;
  }
};
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  map<Center, int> mapka;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      Center c(v[i].first, v[i].second, v[j].first, v[j].second);
      mapka[c]++;
    }
  }
  long long ans = 0;
  for (map<Center, int>::iterator it = mapka.begin(); it != mapka.end(); ++it) {
    int c = it->second;
    ans += 1ll * c * (c - 1) / 2;
  }
  cout << ans << "\n";
  return 0;
}
