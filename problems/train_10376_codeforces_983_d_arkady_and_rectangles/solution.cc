#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<int> X[800005 * 2];
struct Event {
  int x, y1, y2, type, color;
} E[200005];
struct Query {
  int x1, y1, x2, y2;
} Q[100005];
int cnt;
pair<int, int> Range[200005];
map<int, int> Mx, My;
int Min[800005 * 2], Max[800005 * 2];
bool seen[200005], Erased[200005];
void Read() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    Mx[x1] = 1;
    Mx[x2] = 1;
    My[y1] = 1;
    My[y2] = 1;
    Q[i] = {x1, y1, x2, y2};
  }
  int aux = 0;
  for (auto it = Mx.begin(); it != Mx.end(); it = next(it)) it->second = ++aux;
  aux = 0;
  for (auto it = My.begin(); it != My.end(); it = next(it)) it->second = ++aux;
}
inline bool cmp(Event a, Event b) {
  if (a.x == b.x) return a.type < b.type;
  return a.x < b.x;
}
void precalcEvent() {
  for (int i = 1; i <= N; i++) {
    E[++cnt] = {Mx[Q[i].x1], My[Q[i].y1], My[Q[i].y2], 0, i};
    E[++cnt] = {Mx[Q[i].x2], My[Q[i].y1], My[Q[i].y2], 1, i};
  }
  sort(E + 1, E + cnt + 1, cmp);
}
void recalc(int node) {
  int minchild = min(Min[node * 2], Min[node * 2 + 1]);
  int maxchild = max(Max[node * 2], Max[node * 2 + 1]);
  int maxnode = -1;
  while (!X[node].empty() && Erased[X[node].top()]) {
    X[node].pop();
  }
  if (!X[node].empty()) {
    maxnode = X[node].top();
  }
  if (maxnode > maxchild) {
    if (seen[maxnode] == 1 || maxnode < minchild) {
      Max[node] = -1;
    } else
      Max[node] = maxnode;
  } else
    Max[node] = maxchild;
  Min[node] = max(minchild, maxnode);
}
void Update(int K, int L, int R, int x, int y, int action, int id) {
  if (L > R || L > y || R < x) return;
  if (L >= x && R <= y) {
    if (action == 0) X[K].push(id);
    recalc(K);
    return;
  }
  Update(K * 2, L, (L + R) / 2, x, y, action, id);
  Update(K * 2 + 1, (L + R) / 2 + 1, R, x, y, action, id);
  recalc(K);
}
int main() {
  Read();
  precalcEvent();
  for (int i = 1; i <= 800000 * 2; i++) Max[i] = -1;
  int point = 1;
  for (int i = 1; i <= cnt; i++) {
    while (E[point].x == i) {
      int x = E[point].y1, y = E[point].y2, action = E[point].type,
          id = E[point].color;
      if (action == 1) Erased[id] = 1;
      if (action == 0) Range[id] = make_pair(x, y);
      Update(1, 1, 2 * N, x, y - 1, action, id);
      ++point;
    }
    while (Max[1] != -1) {
      seen[Max[1]] = 1;
      Update(1, 1, 2 * N, Range[Max[1]].first, Range[Max[1]].second - 1, -1,
             Max[1]);
    }
  }
  int ans = 1;
  for (int i = 1; i <= N; i++)
    if (seen[i] == 1) ++ans;
  printf("%d\n", ans);
  return 0;
}
