#include <bits/stdc++.h>
using namespace std;
using Int = long long;
constexpr static int mod = 1e9 + 7;
constexpr static int inf = (1 << 30) - 1;
constexpr static Int infll = (1LL << 61) - 1;
int Competitive_Programming =
    (ios_base::sync_with_stdio(false), cin.tie(nullptr),
     cout << fixed << setprecision(15), 0);
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
int main() {
  Int N, D, M;
  cin >> N >> D >> M;
  vector<Int> a(N);
  vector<Int> low, high;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (a[i] > M)
      high.push_back(a[i]);
    else
      low.push_back(a[i]);
  }
  sort(low.rbegin(), low.rend());
  sort(high.rbegin(), high.rend());
  vector<Int> lowsum(low.size() + 1), highsum(high.size() + 1);
  for (int i = 0; i < low.size(); i++) lowsum[i + 1] = lowsum[i] + low[i];
  for (int i = 0; i < high.size(); i++) highsum[i + 1] = highsum[i] + high[i];
  Int ans = 0, hsz = highsum.size(), lsz = lowsum.size();
  for (int i = 0; i < lsz; i++)
    ans = max(ans, highsum[min(hsz - 1, (N - i + D) / (D + 1))] + lowsum[i]);
  cout << ans << "\n";
}
