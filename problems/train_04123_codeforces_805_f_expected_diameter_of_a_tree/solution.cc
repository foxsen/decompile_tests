#include <bits/stdc++.h>
using namespace std;
int fa[100005], judge[100005];
int mx[100005], dis[100005];
int num[100005];
bool vis[100005];
vector<int> tot[100005];
vector<int> edge[100005];
vector<long long> pre[100005];
long long maxdis;
int maxpos;
queue<int> q;
map<long, double> mp;
void BFS(int x) {
  while (!q.empty()) q.pop();
  q.push(x);
  while (!q.empty()) {
    int temp = q.front();
    q.pop();
    if (vis[temp]) continue;
    vis[temp] = 1;
    if (dis[temp] > maxdis) {
      maxdis = dis[temp];
      maxpos = temp;
    }
    for (int i = 0; i < edge[temp].size(); i++) {
      if (!vis[edge[temp][i]]) {
        dis[edge[temp][i]] = dis[temp] + 1;
        q.push(edge[temp][i]);
      }
    }
  }
}
void dfs(int i, int dep, int coo) {
  for (int j = 0; j < edge[i].size(); j++) {
    int temp = edge[i][j];
    if (judge[temp] == coo)
      continue;
    else {
      mx[temp] = max(mx[temp], (dep + 1));
      judge[temp]++;
      dfs(temp, dep + 1, coo);
    }
  }
}
int getfa(int i) {
  if (fa[i] != i)
    return fa[i] = getfa(fa[i]);
  else
    return fa[i];
}
void uni(int a, int b) {
  getfa(a);
  getfa(b);
  fa[fa[a]] = fa[b];
}
int main() {
  int n, m, q, u, v;
  cin >> n >> m >> q;
  memset(vis, 0, sizeof(vis));
  memset(mx, 0, sizeof(mx));
  memset(judge, 0, sizeof(judge));
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
    uni(u, v);
  }
  for (int i = 1; i <= n; i++) {
    getfa(i);
  }
  int id = 1;
  for (int i = 1; i <= n; i++) {
    if (fa[i] == i) {
      num[fa[i]] = id++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!judge[i]) {
      maxdis = 0;
      maxpos = i;
      memset(vis, 0, sizeof(vis));
      memset(dis, 0, sizeof(dis));
      BFS(i);
      judge[maxpos]++;
      dfs(maxpos, 0, 1);
      maxdis = 0;
      memset(vis, 0, sizeof(vis));
      memset(dis, 0, sizeof(dis));
      BFS(maxpos);
      judge[maxpos]++;
      dfs(maxpos, 0, 2);
    }
  }
  for (int i = 1; i <= n; i++) tot[fa[i]].push_back(mx[i]);
  for (int i = 1; i <= n; i++) sort(tot[i].begin(), tot[i].end());
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < tot[i].size(); j++) {
      pre[i].push_back(tot[i][j]);
    }
    for (int j = 1; j < pre[i].size(); j++) {
      pre[i][j] += pre[i][j - 1];
    }
  }
  while (q--) {
    scanf("%d%d", &u, &v);
    if (fa[u] == fa[v]) {
      printf("-1\n");
      continue;
    }
    if (mp[num[fa[u]] * id + num[fa[v]]] != 0 && id <= 10000) {
      printf("%.10lf\n", mp[num[fa[u]] * id + num[fa[v]]]);
      continue;
    }
    double ans = 0;
    long long mxx = max(tot[fa[u]][tot[fa[u]].size() - 1],
                        tot[fa[v]][tot[fa[v]].size() - 1]);
    if (tot[fa[u]].size() == 0 && tot[fa[v]].size() == 0) {
      ans = 0;
    } else if (tot[fa[u]].size() == 0) {
      ans = (double)(pre[fa[v]][tot[fa[v]].size() - 1]) /
            (double)(tot[fa[v]].size());
    } else if (tot[fa[v]].size() == 0) {
      ans = (double)(pre[fa[u]][tot[fa[u]].size() - 1]) /
            (double)(tot[fa[u]].size());
    } else {
      if (tot[fa[u]].size() > tot[fa[v]].size()) swap(u, v);
      for (int i = 0; i < tot[fa[u]].size(); i++) {
        long long su = 0;
        if (tot[fa[v]][tot[fa[v]].size() - 1] + tot[fa[u]][i] + 1 <= mxx) {
          su += ((mxx - 1) * tot[fa[v]].size());
        } else if ((tot[fa[v]][0] + tot[fa[u]][i] + 1) >= mxx) {
          su += (pre[fa[v]][tot[fa[v]].size() - 1]);
          su += (tot[fa[u]][i] * tot[fa[v]].size());
        } else {
          long long temp = lower_bound(tot[fa[v]].begin(), tot[fa[v]].end(),
                                       mxx - tot[fa[u]][i] - 1) -
                           tot[fa[v]].begin();
          su += (pre[fa[v]][tot[fa[v]].size() - 1] - pre[fa[v]][temp - 1] +
                 tot[fa[u]][i] * (tot[fa[v]].size() - temp));
          su += ((mxx - 1) * (temp));
        }
        ans += (double)su / (double)(tot[fa[v]].size() * tot[fa[u]].size());
      }
    }
    ans += 1;
    printf("%.10lf\n", ans);
    mp[num[fa[u]] * id + num[fa[v]]] = ans;
    mp[num[fa[v]] * id + num[fa[u]]] = ans;
  }
}
