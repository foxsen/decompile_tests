#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 5;
struct Node {
  int dp[5][5];
} tree[maxn << 2];
int n, q;
char ch[maxn];
map<char, int> id;
inline void init(Node &t) {
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) t.dp[i][j] = inf;
}
Node Merge(Node a, Node b) {
  Node tmp;
  init(tmp);
  for (int i = 0; i <= 4; i++)
    for (int j = i; j <= 4; j++)
      for (int k = i; k <= j; k++)
        tmp.dp[i][j] = min(tmp.dp[i][j], a.dp[i][k] + b.dp[k][j]);
  return tmp;
}
void display(Node t) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) printf("%d ", t.dp[i][j]);
    cout << endl;
  }
}
void buildtree(int l, int r, int o) {
  if (l == r) {
    init(tree[o]);
    for (int i = 0; i < 5; i++) tree[o].dp[i][i] = 0;
    int pos = id[ch[l]];
    if (pos <= 3) tree[o].dp[pos][pos] = 1, tree[o].dp[pos][pos + 1] = 0;
    if (pos == 4) tree[o].dp[3][3] = tree[o].dp[4][4] = 1;
    return;
  }
  int mid = (l + r) / 2;
  if (l <= mid) buildtree(l, mid, o << 1);
  if (r > mid) buildtree(mid + 1, r, o << 1 | 1);
  tree[o] = Merge(tree[o << 1], tree[o << 1 | 1]);
}
Node ans;
void query(int ql, int qr, int l, int r, int o) {
  if (ql <= l && qr >= r) {
    if (ql == l)
      ans = tree[o];
    else
      ans = Merge(ans, tree[o]);
    return;
  }
  int mid = (l + r) / 2;
  if (ql <= mid) query(ql, qr, l, mid, o << 1);
  if (qr > mid) query(ql, qr, mid + 1, r, o << 1 | 1);
}
int main() {
  int cnt = 4;
  id['2'] = 0, id['0'] = 1, id['1'] = 2, id['7'] = 3, id['6'] = 4;
  for (char i = '3'; i <= '9'; i++)
    if (id.count(i) == 0) id[i] = ++cnt;
  cin >> n >> q;
  scanf("%s", ch + 1);
  buildtree(1, n, 1);
  for (int i = 1; i <= q; i++) {
    int ql, qr;
    scanf("%d%d", &ql, &qr);
    init(ans);
    query(ql, qr, 1, n, 1);
    if (ans.dp[0][4] >= inf)
      puts("-1");
    else
      printf("%d\n", ans.dp[0][4]);
  }
  return 0;
}
