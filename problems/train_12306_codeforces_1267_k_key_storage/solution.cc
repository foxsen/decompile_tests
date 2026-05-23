#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int cnt[MAX];
long long bin[MAX][MAX];
void init() {
  for (int i = 0; i < int(100); i++) {
    bin[i][0] = bin[i][i] = 1;
    for (int j = 1; j < i; j++) bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
  }
}
long long dp[MAX][MAX];
bool visited[MAX][MAX];
long long solve(int i, int c) {
  visited[i][c] = true;
  if (i <= 1) {
    dp[i][c] = bin[c + cnt[i]][cnt[i]] * solve(i + 1, c + cnt[i]);
  } else if (c == 0)
    dp[i][c] = 1;
  else {
    dp[i][c] = bin[c - 1 + cnt[i]][cnt[i]] * solve(i + 1, c - 1 + cnt[i]);
  }
  return dp[i][c];
}
int main() {
  init();
  int T;
  scanf("%d", &T);
  for (int t = 0; t < int(T); t++) {
    long long k;
    scanf("%lld", &k);
    for (int i = 0; i < int(MAX); i++) cnt[i] = 0;
    int big = 2;
    for (long long i = 2;; i++) {
      if (k == 0) {
        break;
      }
      cnt[k % i]++;
      big = i;
      k /= i;
    }
    long long ans = solve(0, 0);
    if (cnt[0] > 0) {
      cnt[0]--;
      int tmp = cnt[0] + cnt[1];
      bool q = false;
      for (int i = 2; i < big; i++) {
        tmp--;
        if (tmp < 0) q = true;
        tmp += cnt[i];
      }
      if (!q) ans -= solve(0, 0);
    }
    printf("%lld\n", max(ans - 1ll, 0ll));
  }
}
