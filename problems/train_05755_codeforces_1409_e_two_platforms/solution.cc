#include <bits/stdc++.h>
using namespace std;
template <class T>
long long size(const T& x) {
  return x.size();
}
template <class T>
T smod(T a, T b) {
  return (a % b + b) % b;
}
long long n, k;
vector<long long> X;
vector<pair<long long, pair<long long, long long> > > A;
vector<vector<long long> > mem;
long long dp(int at, int chosen) {
  if (at >= n) return 0;
  if (mem[at][chosen] != -1) return mem[at][chosen];
  long long mx = 0;
  if (chosen < 2) {
    mx = max(mx, A[at].first + dp(A[at].second.second + 1, chosen + 1));
  }
  mx = max(mx, dp(at + 1, chosen));
  return mem[at][chosen] = mx;
}
void solve() {
  cin >> n >> k;
  mem = vector<vector<long long> >(n + 10, vector<long long>(3, -1));
  X = vector<long long>(n);
  A = vector<pair<long long, pair<long long, long long> > >(n);
  for (long long i = (0); i < (n); ++i) {
    cin >> X[i];
  }
  sort(X.begin(), X.end());
  for (long long i = (0); i < (n); ++i) {
    long long a;
    cin >> a;
  }
  for (long long i = (0); i < (n); ++i) {
    auto r = upper_bound(X.begin(), X.end(), X[i] + k);
    int index = r - X.begin() - 1;
    A[i] = pair<long long, pair<long long, long long> >(
        index - i + 1, pair<long long, long long>(i, index));
  }
  cout << dp(0, 0) << endl;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) solve();
}
