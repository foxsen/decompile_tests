#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-12;
const int maxn = 100000 + 1912;
bool maximize(long long &a, const long long &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
bool minimize(long long &a, const long long &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
class Tree {
 public:
  int n;
  vector<int> V[maxn];
  int chil[maxn];
  long long Go[maxn];
  long long BestGo;
  int depth[maxn];
  long long GoodU[maxn], GoodY[maxn], dp[maxn];
  int n1, n3;
  long long bestALL, sum;
  void Load(int _n) {
    memset(chil, 0, sizeof(chil));
    memset(depth, 0, sizeof(depth));
    n = _n;
    for (int i = 1; i <= n - 1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      V[u].push_back(v);
      V[v].push_back(u);
    }
  }
  void dfsFirst(const int u, const int prev) {
    chil[u] = 1;
    Go[u] = 0;
    for (int i = 0; i < ((int)V[u].size()); i++) {
      int v = V[u][i];
      if (v == prev) continue;
      depth[v] = depth[u] + 1;
      dfsFirst(v, u);
      Go[u] += Go[v] + chil[v];
      chil[u] += chil[v];
    }
  }
  void dfsSecond(const int u, const int prev) {
    for (int i = 0; i < ((int)V[u].size()); i++) {
      int v = V[u][i];
      if (v == prev) continue;
      Go[v] = Go[u] + n - chil[v] * 2;
      dfsSecond(v, u);
    }
  }
  void Init() {
    dfsFirst(1, 0);
    dfsSecond(1, 0);
    BestGo = 0;
    for (int i = 1; i <= n; i++) BestGo = max(BestGo, Go[i]);
    for (int i = 1; i <= n; i++) sum += Go[i];
    sum /= 2;
  }
  void dfsFou(const int u, const int prev) {
    long long bestU = -1, bestY = -1, best2U = -1, best2Y = -1;
    int idbestU = -1, idbestY = -1;
    for (int i = 0; i < ((int)V[u].size()); i++) {
      int v = V[u][i];
      if (v == prev) continue;
      dfsFou(v, u);
      if (maximize(bestU, GoodU[v])) {
        idbestU = v;
      }
      if (maximize(bestY, GoodY[v])) {
        idbestY = v;
      }
    }
    for (int i = 0; i < ((int)V[u].size()); i++) {
      int v = V[u][i];
      if (v == prev) continue;
      if (v != idbestU) {
        maximize(best2U, GoodU[v]);
      }
      if (v != idbestY) {
        maximize(best2Y, GoodY[v]);
      }
    }
    if (bestY != -1)
      maximize(dp[u], Go[u] * n3 + bestY - 2LL * n1 * n3 * depth[u]);
    if (bestU != -1)
      maximize(dp[u], Go[u] * n1 + bestU - 2LL * n1 * n3 * depth[u]);
    if (idbestU != -1 && idbestY != -1) {
      if (idbestU == idbestY) {
        if (best2Y != -1)
          maximize(dp[u], bestU + best2Y - 2LL * n1 * n3 * depth[u]);
        if (best2U != -1)
          maximize(dp[u], best2U + bestY - 2LL * n1 * n3 * depth[u]);
      } else
        maximize(dp[u], bestU + bestY - 2LL * n1 * n3 * depth[u]);
    }
    GoodU[u] = bestU;
    maximize(GoodU[u], Go[u] * n3 + 1LL * depth[u] * n1 * n3);
    GoodY[u] = bestY;
    maximize(GoodY[u], Go[u] * n1 + 1LL * depth[u] * n1 * n3);
  }
  long long Solve(int _n1, int _n3) {
    n1 = _n1, n3 = _n3;
    dfsFou(1, 0);
    long long res = 0;
    for (int i = 1; i <= n; i++) res = max(res, dp[i]);
    bestALL = res;
    return res;
  }
} T[3];
void ReadData() {
  int x, y, z;
  scanf("%d%d%d", &x, &y, &z);
  T[0].Load(x);
  T[1].Load(y);
  T[2].Load(z);
  for (int i = 0; i < 3; i++) T[i].Init();
  T[0].Solve(y, z);
  T[1].Solve(x, z);
  T[2].Solve(x, y);
}
long long Solve(int fi, int se, int th) {
  long long res = T[fi].sum + T[se].sum + T[th].sum;
  res += T[fi].BestGo * T[se].n + 1LL * T[fi].n * T[se].n;
  res += 1LL * T[se].n * T[th].n + T[th].BestGo * T[se].n;
  res += 1LL * T[th].n * T[fi].BestGo + 2LL * T[fi].n * T[th].n +
         T[th].BestGo * T[fi].n;
  res += T[se].bestALL;
  return res;
}
void Process() {
  long long res = 0;
  res = max(res, Solve(1, 0, 2));
  res = max(res, Solve(0, 1, 2));
  res = max(res, Solve(0, 2, 1));
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ReadData();
  Process();
}
