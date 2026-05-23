#include <bits/stdc++.h>
using namespace std;
int arr[310], nex[310], T, N;
bool can, isRoot[310];
void dfs(int x, int val) {
  if (T < 0) return;
  arr[x] += val;
  if (nex[x] != -1) {
    T -= arr[x];
    dfs(nex[x], arr[x]);
  }
}
long long int memo[310][100000 + 100];
long long int solve(int pos, int val) {
  if (pos == 0) return val == 0;
  if (val <= 0) return val == 0;
  if (memo[pos][val] != -1) return memo[pos][val];
  long long int ret = solve(pos - 1, val);
  if (val - arr[pos] >= 0)
    ret = (ret + solve(pos, val - arr[pos])) % 1000000007;
  return memo[pos][val] = ret;
}
long long int t[100000 + 100];
int main() {
  int Q, x, y;
  while (cin >> N >> Q >> T) {
    for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    memset(nex, -1, sizeof nex);
    memset(isRoot, true, sizeof isRoot);
    for (int i = 0; i < Q; i++) {
      scanf("%d %d", &x, &y);
      nex[x] = y;
      isRoot[y] = false;
    }
    bool in = false;
    for (int i = 1; i <= N; i++)
      if (isRoot[i] && nex[i] != -1) {
        in = true;
        dfs(i, 0);
      }
    if ((Q > 0 && in == false) || T < 0) {
      cout << 0 << endl;
      return 0;
    }
    memset(memo, -1, sizeof memo);
    t[0] = 1;
    for (int i = 1; i <= N; i++)
      for (int j = 0; j <= T; j++) {
        if (j - arr[i] >= 0) t[j] = (t[j] + t[j - arr[i]]) % 1000000007;
      }
    cout << t[T] << endl;
  }
  return 0;
}
