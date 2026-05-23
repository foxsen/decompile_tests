#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int N, M;
string s;
int memo[MAXN], ans[MAXN], preSum[MAXN], consecutive[MAXN][2];
void input() {
  cin >> N;
  getline(cin, s);
  getline(cin, s);
  cin >> M;
  s = " " + s;
}
int solve() {
  for (int i = 1; i <= N; i++) preSum[i] = preSum[i - 1] + (s[i] == '?');
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 2; j++) consecutive[i][j] = consecutive[i - 1][j];
    if (s[i] == 'a' && i % 2 == 0)
      consecutive[i][0]++;
    else if (s[i] == 'a' && i % 2 == 1)
      consecutive[i][1]++;
    else if (s[i] == 'b' && i % 2 == 0)
      consecutive[i][1]++;
    else if (s[i] == 'b' && i % 2 == 1)
      consecutive[i][0]++;
  }
  for (int i = M; i <= N; i++) {
    int state = (i - M) % 2;
    if (consecutive[i - M][state] == consecutive[i][state % 2]) {
      int nxtMemo = memo[i - M] + 1;
      int nxtAns = ans[i - M] + preSum[i] - preSum[i - M];
      if (nxtMemo > memo[i - 1])
        memo[i] = nxtMemo, ans[i] = nxtAns;
      else if (nxtMemo == memo[i - 1])
        memo[i] = nxtMemo, ans[i] = min(ans[i - 1], nxtAns);
      else
        memo[i] = memo[i - 1], ans[i] = ans[i - 1];
    } else
      memo[i] = memo[i - 1], ans[i] = ans[i - 1];
  }
  return ans[N];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  input();
  cout << solve();
  return 0;
}
