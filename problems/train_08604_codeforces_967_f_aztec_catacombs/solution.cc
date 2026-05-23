#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> G[300005];
int pre[300005];
int d[300005];
int maxn;
void dfs() {
  for (int s = 1; s <= n; s++) {
    d[s] = 0x3f3f3f3f;
  }
  memset(pre, 0, sizeof(pre));
  maxn = 0;
  queue<int> q;
  q.push(1);
  d[1] = 0;
  pre[1] = 0;
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    maxn = max(maxn, d[t]);
    int sz = G[t].size();
    for (int s = 0; s < sz; s++)
      if (d[G[t][s]] > d[t] + 1) {
        d[G[t][s]] = d[t] + 1;
        pre[G[t][s]] = t;
        q.push(G[t][s]);
      }
  }
}
int fuck_bfs(int x) {
  for (int s = 0; s <= n; s++) {
    d[s] = 0x3f3f3f3f;
  }
  queue<int> q;
  q.push(x);
  pre[x] = 0;
  int ans = 0;
  d[x] = 0;
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    if (d[t] == 2) {
      ans = t;
    }
    int sz = G[t].size();
    for (int s = 0; s < sz; s++) {
      if (d[G[t][s]] > d[t] + 1 && G[t][s] != 1) {
        d[G[t][s]] = d[t] + 1;
        pre[G[t][s]] = t;
        q.push(G[t][s]);
      }
    }
  }
  return ans;
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int s = 0; s < m; s++) {
      int a, b;
      scanf("%d%d", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    dfs();
    if (n == 30 && m == 103) {
    }
    if (d[n] < 4) {
      stack<int> q;
      printf("%d\n", d[n]);
      while (n) {
        q.push(n);
        n = pre[n];
      }
      printf("%d", q.top());
      q.pop();
      while (!q.empty()) {
        printf(" %d", q.top());
        q.pop();
      }
      printf("\n");
    } else {
      if (maxn < 2) {
        int spot = 0, t;
        int sz = G[1].size();
        for (int s = 0; s < sz; s++) {
          spot = fuck_bfs(G[1][s]);
          if (spot) {
            t = G[1][s];
            break;
          }
        }
        if (spot) {
          printf("5\n");
          stack<int> q;
          q.push(n);
          q.push(t);
          while (spot) {
            q.push(spot);
            spot = pre[spot];
          }
          q.push(1);
          printf("%d", q.top());
          q.pop();
          while (!q.empty()) {
            printf(" %d", q.top());
            q.pop();
          }
          printf("\n");
        } else
          printf("-1\n");
      } else {
        printf("4\n");
        stack<int> q;
        int t;
        for (int s = 1; s <= n; s++) {
          if (d[s] == 2) {
            t = s;
            break;
          }
        }
        q.push(n);
        q.push(1);
        while (t) {
          q.push(t);
          t = pre[t];
        }
        printf("%d", q.top());
        q.pop();
        while (!q.empty()) {
          printf(" %d", q.top());
          q.pop();
        }
        printf("\n");
      }
    }
  }
}
