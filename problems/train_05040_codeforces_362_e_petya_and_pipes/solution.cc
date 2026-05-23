#include <bits/stdc++.h>
using namespace std;
struct edge {
  int b;
  int cap, f, cost;
  int rev_id;
};
vector<edge> E[55];
int dist[55];
int from[55];
int from_edge[55];
int res[55];
struct cmp {
  bool operator()(int &a, int &b) { return dist[a] > dist[b]; }
};
int find_aug(int s, int t) {
  for (int n = s; n <= t; ++n) {
    dist[n] = 1e9;
    res[n] = 0;
  }
  priority_queue<int, vector<int>, cmp> Q;
  dist[s] = 0;
  res[s] = 1e9;
  Q.push(s);
  int x;
  while (Q.size() > 0) {
    x = Q.top();
    Q.pop();
    if (x == t) {
      return res[t];
    }
    for (int n = 0; n < E[x].size(); ++n) {
      int y = E[x][n].b;
      int c = min(E[x][n].cap - E[x][n].f, res[x]);
      int newdist = dist[x] + E[x][n].cost;
      if (c && (newdist < dist[y])) {
        dist[y] = newdist;
        res[y] = c;
        from[y] = x;
        from_edge[y] = n;
        Q.push(y);
      }
    }
  }
  return res[t];
}
int mincostmaxflow(int N, int K) {
  int Ans = 0;
  int flow = 0;
  int temp = 0;
  int cst = 0;
  while (temp = find_aug(0, N - 1)) {
    if (dist[N - 1] > 0) {
      temp = min(temp, (int)1);
    }
    for (int j = N - 1, i = from[j]; j != 0; j = i, i = from[j]) {
      int x = from_edge[j];
      int y = E[i][x].rev_id;
      E[i][x].f += temp;
      E[j][y].f -= temp;
    }
    cst += temp * dist[N - 1];
    flow += temp;
    if (cst <= K) {
      Ans = max(Ans, flow);
    } else {
      break;
    }
  }
  return Ans;
}
void add_edge(int a, int b, int cap, int cost) {
  edge x = {b, cap, 0, cost, (int)E[b].size()};
  edge y = {a, 0, 0, -cost, (int)E[a].size()};
  E[a].push_back(x);
  E[b].push_back(y);
}
int main() {
  int N, K;
  cin >> N >> K;
  int x;
  for (int n = 0; n < N; ++n) {
    for (int m = 0; m < N; ++m) {
      scanf("%d", &x);
      if (!x) {
        continue;
      }
      add_edge(n, m, x, 0);
      add_edge(n, m, K, 1);
    }
  }
  int Ans = mincostmaxflow(N, K);
  cout << Ans << endl;
  return 0;
}
