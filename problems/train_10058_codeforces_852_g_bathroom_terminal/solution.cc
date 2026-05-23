#include <bits/stdc++.h>
using namespace std;
int Trie[5000050][5], tz;
int N, M;
int leaf[5000050];
int cnt[5000050];
char B[55];
int lc;
int chk[5000010];
int v[100010], vz;
int ans;
void dfs(int x, int y) {
  if (B[x] == 0) {
    if (chk[y] == 0) {
      chk[y] = 1;
      v[vz++] = y;
      ans += cnt[y];
    }
    return;
  }
  if (B[x] != '?') {
    int c = B[x] - 'a';
    if (Trie[y][c] > 0) dfs(x + 1, Trie[y][c]);
  } else {
    dfs(x + 1, y);
    for (int i = 0; i < 5; i++)
      if (Trie[y][i] > 0) dfs(x + 1, Trie[y][i]);
  }
}
void solve() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    char ch[55];
    scanf("%s", ch);
    int L = (int)strlen(ch);
    int now = 0;
    for (int a = 0; a < L; a++) {
      int c = ch[a] - 'a';
      if (Trie[now][c] == 0) Trie[now][c] = ++tz;
      now = Trie[now][c];
    }
    cnt[now]++;
  }
  for (int i = 0; i < M; i++) {
    scanf("%s", B);
    ans = 0;
    dfs(0, 0);
    printf("%d\n", ans);
    for (int a = 0; a < vz; a++) chk[v[a]] = 0;
    vz = 0;
  }
}
int main() {
  int Tc = 1;
  for (int tc = 1; tc <= Tc; tc++) {
    solve();
  }
  return 0;
};
