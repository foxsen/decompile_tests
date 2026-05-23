#include <bits/stdc++.h>
using namespace std;
int N, M;
unsigned long long a[100000];
unsigned long long b[100000];
int main() {
  cin.sync_with_stdio(false);
  cin >> N >> M;
  unsigned long long sa, sb;
  sa = sb = 0ULL;
  for (int i = 0; i < N; ++i) cin >> a[i], sa += a[i];
  for (int i = 0; i < M; ++i) cin >> b[i], sb += b[i];
  sort(a, a + N);
  sort(b, b + M);
  unsigned long long ans = ULLONG_MAX;
  unsigned long long s = 0ULL;
  int n1 = 0;
  for (int i = 0; i < N; ++i) {
    ans = min(ans, sb * (N - i) + s);
    s += a[i];
  }
  s = 0ULL;
  for (int i = 0; i < M; ++i) {
    ans = min(ans, sa * (M - i) + s);
    s += b[i];
  }
  cout << ans << endl;
  return 0;
}
