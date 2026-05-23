#include <bits/stdc++.h>
using namespace std;

#define INF 0x7fffffffffff
typedef long long int LLI;

int N;
int M;
LLI ts[1145];
LLI ss[1145];
LLI vs[3145];
LLI hs[3145];
LLI dp[1145][3145];

int main() {
  scanf("%d%d", &N, &M);

  for (int i=1; i<=N; i++) {
    scanf("%lld%lld", &vs[i], &hs[i]);
  }

  for (int i=1; i<=M; i++) {
    scanf("%lld%lld", &ts[i], &ss[i]);
  }

  for (int i=0; i<=M; i++) {
    for (int j=0; j<=N; j++) {
      dp[i][j] = -INF;
    }
  }
  
  dp[0][0] = 0;
  for (int i=1; i<=M; i++) {
    LLI accv = 0;
    for (int j=0; j<=N; j++) {
      accv += vs[j];
      if (accv > ts[i]) break;
      if (j >= 1) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
      if (j >= 2) dp[i][j] = max(dp[i][j], dp[i][j-1] + llabs(hs[j-1]-hs[j]));
    }

    LLI acch = 0;
    for (int j=0; j<=N; j++) {
      dp[i][j] = max(dp[i][j], dp[i-1][j]);
      acch += hs[j];
      if (acch+dp[i][j] < ss[i]) dp[i][j] = -INF; 
    }
  }

  for (int i=0; i<=N; i++) {
    if (dp[M][i] >= 0) {
      LLI ans = ts[M];
      for (int j=1; j<=i; j++) ans -= vs[j];
      assert (ans >= 0);
      printf("%lld\n", ans);
      return 0;
    }
  }

  puts("-1");
}