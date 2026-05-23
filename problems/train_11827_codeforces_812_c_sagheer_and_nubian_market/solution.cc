#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592654;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
}
int x, s;
vector<long long> v(100000);
vector<long long>::iterator it;
long long mn = LLONG_MAX, ans = 0, sol;
bool valid(long long m) {
  long long sum = s;
  int f;
  ans = 0;
  vector<long long> mm;
  for (int i = 0; i < x; i++) {
    f = i + 1;
    long long n = (v[i]) + (m * f);
    mm.push_back(n);
  }
  sort((mm).begin(), (mm).end());
  for (int(i) = 0; (i) < (long long)(m); (i)++) ans += mm[i];
  if (ans <= s)
    return 1;
  else
    return 0;
}
void search(int k) {
  long long l = 1, r = k;
  while (l <= r) {
    long long md = (l + r) / 2;
    if (valid(md)) {
      l = md + 1;
      if (md > sol) mn = ans, sol = md;
    } else
      r = md - 1;
  }
}
int main() {
  fast();
  cin >> x >> s;
  for (int(i) = 0; (i) < (long long)(x); (i)++) cin >> v[i];
  search(x);
  if (mn == LLONG_MAX) mn = 0;
  cout << sol << " " << mn << endl;
  return 0;
}
