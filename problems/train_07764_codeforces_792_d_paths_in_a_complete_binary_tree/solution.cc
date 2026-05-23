#include <bits/stdc++.h>
using namespace std;
int static_init = []() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout << fixed;
  return 0;
}();
int64_t n, u, q, d;
string s;
vector<int64_t> p;
void move(char c) {
  if (c == 'U') {
    if (p.size() == 1) return;
    p.pop_back();
    if (d == 0)
      d++;
    else
      d *= 2;
    return;
  }
  if (d == 0) return;
  p.push_back(p.back() + (c == 'L' ? -d : d));
  d /= 2;
}
int main() {
  cin >> n >> q;
  while (q-- > 0) {
    cin >> u >> s;
    p.clear();
    p.push_back((n + 1) / 2);
    d = p.back() / 2;
    while (p.back() != u) move(u < p.back() ? 'L' : 'R');
    for (char c : s) move(c);
    cout << p.back() << '\n';
  }
  return 0;
}
