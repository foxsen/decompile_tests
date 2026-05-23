#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2e5 + 9;
const long long INF = 1e12;
long long N, M, f, s, res;
signed main() {
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  for (int A = 1; A <= M; A++) {
    for (int B = 1; B <= M; B++) {
      if (((A * A) % M + (B * B) % M) % M) continue;
      if (N - A < 0 or N - B < 0) continue;
      f = (N - A) / M + 1;
      s = (N - B) / M + 1;
      res += f * s;
    }
  }
  cout << res;
  return 0;
}
