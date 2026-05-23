#include <bits/stdc++.h>
using namespace std;
istream& operator>>(istream& in, pair<int, int>& p) {
  in >> p.first >> p.second;
  return in;
}
pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
int oct(pair<int, int> p) {
  int res = 0;
  if (p.first > 0) res |= 1;
  if (p.second > 0) res |= 2;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  pair<int, int> a, b, c;
  cin >> a >> b >> c;
  if (oct(b - a) == oct(c - a))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
