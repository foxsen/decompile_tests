#include <bits/stdc++.h>
using namespace std;
struct Node {
  int c, w, pos, next;
} E[99999];
int NE, NV;
int head[30000], pe[30000], pv[30000];
bool vis[30000];
int cost[30000];
queue<int> q;
int MCMF(int s, int t) {
  int maxflow = 0, mincost = 0;
  while (true) {
    memset(pv, -1, sizeof(int) * (NV + 1));
    memset(vis, 0, sizeof(bool) * (NV + 1));
    for (int i = 0; i < NV; i++) cost[i] = 100000000;
    cost[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      vis[u] = false;
      for (int i = head[u]; i != -1; i = E[i].next) {
        int v = E[i].pos;
        if (E[i].c && cost[u] + E[i].w < cost[v]) {
          cost[v] = cost[u] + E[i].w;
          if (!vis[v]) {
            vis[v] = true;
            q.push(v);
          }
          pv[v] = u;
          pe[v] = i;
        }
      }
    }
    if (pv[t] == -1) break;
    int aug = -1;
    for (int v = t; v != s; v = pv[v]) {
      if (aug == -1 || aug > E[pe[v]].c) aug = E[pe[v]].c;
    }
    maxflow += aug;
    mincost += cost[t] * aug;
    for (int v = t; v != s; v = pv[v]) {
      E[pe[v]].c -= aug;
      E[pe[v] ^ 1].c += aug;
    }
  }
  return mincost;
}
void Insert(int u, int v, int w, int c, int cc = 0) {
  E[NE].c = c;
  E[NE].pos = v;
  E[NE].w = w;
  E[NE].next = head[u];
  head[u] = NE++;
  E[NE].c = cc;
  E[NE].pos = u;
  E[NE].w = -w;
  E[NE].next = head[v];
  head[v] = NE++;
}
int Map[2005];
int mcnt;
inline int Bin(int key) {
  int l = 0, r = mcnt - 1, m;
  while (l <= r) {
    m = (l + r) >> 1;
    if (Map[m] == key) return m + 1;
    if (Map[m] < key)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
struct node {
  int u, v, w, e;
} task[1005];
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) != EOF) {
    for (int i = 0; i < n; i++)
      scanf("%d%d%d", &task[i].u, &task[i].v, &task[i].w);
    mcnt = 0;
    for (int i = 0; i < n; i++) {
      Map[mcnt++] = task[i].u;
      task[i].v = Map[mcnt++] = task[i].v + task[i].u;
    }
    sort(Map, Map + mcnt);
    mcnt = unique(Map, Map + mcnt) - Map;
    NE = 0;
    NV = mcnt + 2;
    const int T = NV - 1;
    for (int i = 0; i < NV; i++) head[i] = -1;
    Insert(0, 1, 0, k);
    for (int i = 1; i < mcnt; i++) Insert(i, i + 1, 0, 1000000);
    Insert(mcnt, T, 0, k);
    for (int i = 0; i < n; i++) {
      task[i].e = NE;
      Insert(Bin(task[i].u), Bin(task[i].v), -task[i].w, 1);
    }
    int ret = MCMF(0, T);
    if (E[task[0].e].c)
      printf("0");
    else
      printf("1");
    for (int i = 1; i < n; i++) {
      if (E[task[i].e].c)
        printf(" 0");
      else
        printf(" 1");
    }
    printf("\n");
  }
  return 0;
}
