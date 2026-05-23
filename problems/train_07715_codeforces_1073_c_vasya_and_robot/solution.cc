#include <bits/stdc++.h>
using namespace std;
long long x, y;
int n;
string s;
void update(pair<int, int>& p, char c, int d) {
  if (c == 'U')
    p.second += d;
  else if (c == 'D')
    p.second -= d;
  else if (c == 'R')
    p.first += d;
  else
    p.first -= d;
}
bool check_len(pair<int, int> p, long long len) {
  long long d = abs(x - p.first) + abs(y - p.second);
  if (d <= len && (d % 2 == len % 2)) return 1;
  return 0;
}
bool check(long long len) {
  pair<int, int> p(0, 0);
  for (int i = len; i < n; ++i) update(p, s[i], 1);
  int l = 0, r = len;
  while (true) {
    if (check_len(p, len)) return true;
    if (r == n) break;
    update(p, s[l++], 1);
    update(p, s[r++], -1);
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    cin >> n;
    cin >> s;
    cin >> x >> y;
    if (!check(n))
      cout << "-1\n";
    else {
      long long ans = 0;
      long long s = 0, e = n;
      while (s <= e) {
        long long mid = (s + e) / 2;
        if (check(mid)) {
          e = mid - 1;
          ans = mid;
        } else
          s = mid + 1;
      }
      cout << ans << '\n';
    }
  }
}
