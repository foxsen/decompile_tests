#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int pi = acos(-1);
const double EPS = 1e-9;
const int MAX = 1e6;
long long int l, r;
vector<long long int> v, vec;
set<long long int> st;
long long int FindRoot(long long int x) {
  long long int lo = 0, hi = 1e10, mid;
  while (lo < hi - 1) {
    mid = lo + hi >> 1;
    if (mid * mid > x)
      hi = mid;
    else
      lo = mid;
  }
  return lo;
}
void initial() {
  v.push_back(1);
  for (long long int i = 2; i <= 1e6; i++) {
    for (long long int j = i * i * i; j <= 1e18; j *= i) {
      st.insert(j);
      if (j > 1e18 / i) break;
    }
  }
  for (auto it : st) v.push_back(it);
  for (auto it : v) {
    long long int sq = FindRoot(it);
    if (sq * sq == it) continue;
    vec.push_back(it);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  initial();
  int t;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    auto it1 = upper_bound(vec.begin(), vec.end(), r) - v.begin();
    auto it2 = lower_bound(vec.begin(), vec.end(), l) - v.begin();
    long long int ans = it1 - it2;
    cout << ans + (long long int)FindRoot(r) - (long long int)FindRoot(l - 1)
         << "\n";
  }
}
