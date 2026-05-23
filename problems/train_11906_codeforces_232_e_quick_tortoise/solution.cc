#include <bits/stdc++.h>
using namespace std;
const int N = 512;
const int Q = 600011;
int arr[N][N];
int n, lp2[N];
struct query {
  int when;
  int i1, j1, i2, j2;
  query() {}
  query(int when, int i1, int j1, int i2, int j2)
      : when(when), i1(i1), j1(j1), i2(i2), j2(j2) {}
};
int ans[Q];
vector<query> solo[N], Qs[N];
using BM = bitset<N>;
BM dp[N][N];
void solve(int L, int R) {
  if (L == R) {
    int cc = 0;
    vector<int> colors(n, -1);
    for (int i = 0; i < n; i++) {
      if (i == 0 or arr[i][L] != arr[i - 1][L]) cc++;
      colors[i] = cc;
    }
    for (auto q : solo[L]) {
      int qt = q.when;
      int i1 = q.i1, i2 = q.i2;
      ans[qt] = i1 <= i2 and colors[i1] == colors[i2];
    }
  } else {
    int M = (L + R) >> 1;
    if (Qs[M].empty()) {
      solve(L, M);
      solve(M + 1, R);
      return;
    }
    for (int i = 0; i < n; i++)
      for (int j = L; j <= R; j++) dp[i][j].reset();
    for (int i = n - 1; i >= 0; i--) {
      if (arr[i][M]) continue;
      dp[i][M][i] = arr[i][M] == 0;
      if (i < n - 1) dp[i][M] |= dp[i + 1][M];
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = M - 1; j >= L; j--) {
        if (arr[i][j]) continue;
        dp[i][j] = dp[i][j + 1];
        if (i < n - 1) dp[i][j] |= dp[i + 1][j];
      }
    }
    BM tmp[n];
    for (int i = 0; i < n; i++) {
      if (arr[i][M]) continue;
      tmp[i][i] = arr[i][M] == 0;
      if (i > 0) tmp[i] |= tmp[i - 1];
    }
    for (int i = 0; i < n; i++) {
      for (int j = M + 1; j <= R; j++) {
        if (arr[i][j]) continue;
        dp[i][j] = j > M + 1 ? dp[i][j - 1] : tmp[i];
        if (i > 0) dp[i][j] |= dp[i - 1][j];
      }
    }
    for (auto q : Qs[M]) {
      int qt = q.when;
      int i1 = q.i1, j1 = q.j1;
      int i2 = q.i2, j2 = q.j2;
      ans[qt] = (dp[i1][j1] & dp[i2][j2]).any();
    }
    solve(L, M);
    solve(M + 1, R);
  }
}
int pr[N][N];
void getPr(int L, int R) {
  if (L == R) return;
  int M = (L + R) >> 1;
  for (int i = L; i <= M; i++)
    for (int j = M + 1; j <= R; j++) pr[i][j] = pr[j][i] = M;
  getPr(L, M);
  getPr(M + 1, R);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  lp2[0] = -1;
  lp2[1] = 0;
  for (int i = 2; i < N; i++) {
    lp2[i] = lp2[i - 1];
    if ((i & (1 << lp2[i])) == 0) lp2[i]++;
  }
  getPr(0, N - 1);
  int m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int j;
    for (j = 0; j < m; j++) arr[i][j] = s[j] == '#';
    for (; j < N; j++) arr[i][j] = 1;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;
    i1--;
    j1--;
    i2--;
    j2--;
    if (j1 == j2)
      solo[j1].emplace_back(i, i1, j1, i2, j2);
    else {
      Qs[pr[j1][j2]].emplace_back(i, i1, j1, i2, j2);
    }
  }
  solve(0, N - 1);
  for (int i = 0; i < q; i++) cout << (ans[i] ? "Yes\n" : "No\n");
  return 0;
}
