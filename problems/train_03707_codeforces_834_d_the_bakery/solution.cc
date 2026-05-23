#include <bits/stdc++.h>
using namespace std;
const int mxN = 35001;
int A[mxN], dp[mxN][51], cnt[mxN];
int L = 1, R = 1, now = 1;
int Cost(int l, int r) {
  while (R < r) {
    now += !cnt[A[++R]];
    ++cnt[A[R]];
  }
  while (L < l) {
    --cnt[A[L]];
    now -= !cnt[A[L++]];
  }
  while (L > l) {
    now += !cnt[A[--L]];
    ++cnt[A[L]];
  }
  while (R > r) {
    --cnt[A[R]];
    now -= !cnt[A[R--]];
  }
  return now;
}
void dNc(int i, int l, int r, int optl, int optr) {
  if (l > r) return;
  int mid = (l + r) / 2;
  pair<int, int> b = {-mxN, 0};
  for (int k = optl; k <= min(mid, optr); ++k)
    b = max(b, {dp[k - 1][i - 1] + Cost(k, mid), k});
  dp[mid][i] = b.first;
  int opt = b.second;
  dNc(i, l, mid - 1, optl, opt);
  dNc(i, mid + 1, r, opt, optr);
}
int main() {
  ios ::sync_with_stdio(false), cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  ++cnt[A[1]];
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= K; ++j) dp[i][j] = -N;
  }
  dp[0][0] = 0;
  for (int i = 1; i <= K; ++i) dNc(i, 1, N, 1, N);
  cout << dp[N][K];
  return 0;
}
