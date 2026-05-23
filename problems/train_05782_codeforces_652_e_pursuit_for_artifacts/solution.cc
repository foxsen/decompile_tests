#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int N = 3e5 + 10;
int n, m, st, en, w[N], v[N][2];
vector<int> e[N];
vector<pair<int, int> > v2[N];
int low[N], num[N], t[N], br[N];
queue<int> q;
int good[N], t2[N];
void prepare() {
  scanf("%d%d", &n, &m);
  int x, y;
  for (auto i = (1); i <= (m); i++) {
    scanf("%d%d%d", &x, &y, w + i);
    e[x].push_back(i);
    e[y].push_back(i);
    v[i][0] = x;
    v[i][1] = y;
  }
  scanf("%d%d", &st, &en);
}
void DFS(int x, int le) {
  static int top = 0;
  low[x] = num[x] = ++top;
  for (auto i : e[x])
    if (i != le) {
      int y = v[i][0] + v[i][1] - x;
      if (!num[y]) {
        t[y] = i;
        DFS(y, i);
      }
      low[x] = min(low[x], low[y]);
    }
}
void BFS(int st) {
  static int n1 = 0;
  num[st] = ++n1;
  q.push(st);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto i : e[x])
      if (!br[i]) {
        int y = v[i][0] + v[i][1] - x;
        if (w[i]) good[n1] = 1;
        if (!num[y]) {
          num[y] = n1;
          q.push(y);
        }
      }
  }
}
int solve() {
  DFS(st, 0);
  for (auto i = (1); i <= (n); i++)
    if (low[i] >= num[i]) br[t[i]] = 1;
  memset(num, 0, sizeof(num));
  for (auto i = (1); i <= (n); i++)
    if (!num[i]) BFS(i);
  for (auto i = (1); i <= (m); i++)
    if (br[i]) {
      int x = num[v[i][0]], y = num[v[i][1]];
      v2[x].push_back(pair<int, int>(y, w[i]));
      v2[y].push_back(pair<int, int>(x, w[i]));
    }
  st = num[st], en = num[en];
  q.push(st);
  memset(t2, -1, sizeof(t2));
  t2[st] = good[st];
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto i : v2[x])
      if (t2[i.first] == -1) {
        t2[i.first] = t2[x] | i.second | good[i.first];
        q.push(i.first);
      }
  }
  return t2[en];
}
int main() {
  prepare();
  if (solve())
    cout << "YES";
  else
    cout << "NO";
}
