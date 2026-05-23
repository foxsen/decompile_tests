#include <bits/stdc++.h>
using namespace std;
int N, SQRT_N = 1000;
int U, V;
vector<int> Adj[100005];
int Parent[100005];
vector<int> Ord;
int dp[100005], mxch[100005];
int Ans[100005];
void DFS(int Q) {
  for (int i : Adj[Q])
    if (i != Parent[Q]) {
      Parent[i] = Q;
      DFS(i);
    }
  Ord.push_back(Q);
}
int Solve(int K) {
  int mx, mx2;
  for (int Q : Ord) {
    mx = mx2 = mxch[Q] = dp[Q] = 0;
    for (int i : Adj[Q])
      if (i != Parent[Q]) {
        dp[Q] += dp[i];
        if (mx < mxch[i])
          mx2 = mx, mx = mxch[i];
        else if (mx2 < mxch[i])
          mx2 = mxch[i];
      }
    if (mx + mx2 + 1 >= K)
      dp[Q]++;
    else
      mxch[Q] = mx + 1;
  }
  return dp[1];
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i < N; i++) {
    scanf("%d%d", &U, &V);
    Adj[U].push_back(V);
    Adj[V].push_back(U);
  }
  Parent[1] = -1;
  DFS(1);
  for (int i = 1; i <= N && i <= SQRT_N; i++) Ans[i] = Solve(i);
  int beg = SQRT_N + 1;
  int st, en, mid, NowAns;
  while (beg <= N) {
    st = beg, en = N, mid;
    NowAns = Solve(st);
    while (st <= en) {
      mid = (st + en) >> 1;
      if (Solve(mid) == NowAns)
        st = mid + 1;
      else
        en = mid - 1;
    }
    for (int i = beg; i < st; i++) Ans[i] = NowAns;
    beg = st;
  }
  for (int i = 1; i <= N; i++) printf("%d\n", Ans[i]);
}
