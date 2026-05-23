#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int S = 405;
struct edge {
  int to, next, v;
} e[N * 2];
int head[N], tot, n, m;
int dep[N], v[N];
int vis[N], flg[N];
int nd, tr[S][35];
int trr[S][S];
map<long long, int> mp;
long long sta[S];
void add(int x, int y, int v) {
  e[++tot] = (edge){y, head[x], v};
  head[x] = tot;
}
int init_state(int v, long long val) {
  if (mp[val]) return mp[val];
  mp[val] = ++nd;
  sta[nd] = val;
  for (int i = (int)(0); i <= (int)(31); i++) {
    long long nval = val;
    if (val & (1ll << i))
      tr[mp[val]][i] = 1;
    else {
      for (int j = (int)(0); j <= (int)(31); j++)
        if (val & (1ll << j)) nval |= (1ll << (j ^ i));
      tr[mp[val]][i] = init_state(i + 1, nval);
    }
  }
  return mp[val];
}
void dfs(int x, int fa, int &S) {
  dep[x] = dep[fa] + 1;
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa && !vis[e[i].to]) {
      if (!dep[e[i].to]) {
        v[e[i].to] = v[x] ^ e[i].v;
        dfs(e[i].to, x, S);
      } else if (dep[e[i].to] < dep[x]) {
        S = tr[S][v[e[i].to] ^ v[x] ^ e[i].v];
      }
    }
}
struct oppp {
  int op1, op2, op3, op4;
} op[N];
int op_top;
int f[2][S];
const int mo = 1000000007;
void UPD(int &x, int y) { (x += y) >= mo ? x -= mo : 233; }
pair<int, int> q[N];
int top, ST[N], val[N];
int main() {
  nd = 1;
  init_state(0, 1);
  for (int i = (int)(0); i <= (int)(31); i++) tr[1][i] = 1;
  for (int i = (int)(1); i <= (int)(nd); i++) trr[i][1] = trr[1][i] = 1;
  for (int i = (int)(2); i <= (int)(nd); i++)
    for (int j = (int)(2); j <= (int)(nd); j++) {
      trr[i][j] = i;
      if (sta[i] & sta[j] & ((1ll << 32) - 2))
        trr[i][j] = 1;
      else
        for (int k = (int)(1); k <= (int)(31); k++)
          if (sta[j] & (1ll << k))
            if (!(sta[trr[i][j]] & (1ll << k))) trr[i][j] = tr[trr[i][j]][k];
    }
  scanf("%d%d", &n, &m);
  for (int i = (int)(1); i <= (int)(m); i++) {
    int x, y, v;
    scanf("%d%d%d", &x, &y, &v);
    add(x, y, v);
    add(y, x, v);
  }
  for (int i = head[1]; i; i = e[i].next)
    vis[e[i].to] = 1, q[++top] = pair<int, int>(e[i].to, e[i].v);
  vis[1] = 1;
  for (int i = (int)(1); i <= (int)(top); i++) {
    int now = mp[1];
    vis[q[i].first] = 0;
    dfs(q[i].first, 0, now);
    vis[q[i].first] = 1;
    ST[q[i].first] = now;
    val[q[i].first] = q[i].second;
  }
  for (int i = (int)(1); i <= (int)(top); i++)
    if (!flg[q[i].first]) {
      bool ok = 0;
      for (int j = head[q[i].first]; j; j = e[j].next)
        if (e[j].to != 1 && vis[e[j].to]) {
          flg[e[j].to] = 1;
          ++op_top;
          int tmp = trr[ST[q[i].first]][ST[e[j].to]];
          op[op_top].op1 = mp[1];
          op[op_top].op2 = tmp;
          op[op_top].op3 = tmp;
          op[op_top].op4 = tr[tmp][val[q[i].first] ^ val[e[j].to] ^ e[j].v];
          ok = 1;
        }
      if (!ok) {
        ++op_top;
        op[op_top].op1 = mp[1];
        op[op_top].op2 = ST[q[i].first];
        op[op_top].op3 = -1;
        op[op_top].op4 = -1;
      }
    }
  memset(f, 0, sizeof(f));
  f[0][mp[1]] = 1;
  int pre = 0, now = 1;
  for (int i = (int)(1); i <= (int)(op_top); i++) {
    for (int j = (int)(1); j <= (int)(nd); j++) {
      if (op[i].op1 != -1) UPD(f[now][trr[j][op[i].op1]], f[pre][j]);
      if (op[i].op2 != -1) UPD(f[now][trr[j][op[i].op2]], f[pre][j]);
      if (op[i].op3 != -1) UPD(f[now][trr[j][op[i].op3]], f[pre][j]);
      if (op[i].op4 != -1) UPD(f[now][trr[j][op[i].op4]], f[pre][j]);
      f[pre][j] = 0;
    }
    swap(pre, now);
  }
  int ans = 0;
  for (int i = (int)(2); i <= (int)(nd); i++) UPD(ans, f[pre][i]);
  cout << ans;
}
