#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long M = 1e9 + 7;
long long A[N];
map<pair<long long, long long>, pair<long long, long long> > ans;
pair<long long, long long> func(long long x, long long y) {
  if (ans.find(make_pair(x, y)) != ans.end()) return ans[make_pair(x, y)];
  if (x == y) return ans[make_pair(x, y)] = make_pair(0, A[x]);
  long long mid = (x + y) / 2;
  pair<long long, long long> p = make_pair(0LL, 0LL);
  pair<long long, long long> p1 = func(x, mid);
  pair<long long, long long> p2 = func(mid + 1, y);
  if (p1.second + p2.second >= 10) p.first += 1;
  p.first += p1.first + p2.first;
  p.second = (p1.second + p2.second) % 10;
  return ans[make_pair(x, y)] = p;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> A[i];
  long long q;
  cin >> q;
  while (q--) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << func(x, y).first << "\n";
  }
  return 0;
}
