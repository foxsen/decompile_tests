#include <bits/stdc++.h>
constexpr auto MAXN = 5000 << 1;
constexpr auto MAXM = MAXN;
short inque[MAXN], color[MAXM];
bool cyc = false;
struct Edge {
  int to, ID;
  Edge() {}
  Edge(const int& ito, const int& iID) : to(ito), ID(iID) {}
};
std::vector<Edge> G[MAXN];
void Dfs(const int nowAt) {
  inque[nowAt] = true;
  for (const auto& it : G[nowAt])
    if (inque[it.to] == -1) {
      Dfs(it.to);
      color[it.ID] = 1;
    } else if (inque[it.to] == false) {
      color[it.ID] = 1;
    } else {
      cyc = true;
      color[it.ID] = 2;
    }
  inque[nowAt] = false;
}
signed main(void) {
  memset(inque, -1, sizeof(inque));
  int totNodes, totEdges;
  int fr, to;
  scanf("%d%d", &totNodes, &totEdges);
  for (int i = 0; i < totEdges; i++) {
    scanf("%d%d", &fr, &to);
    --fr;
    --to;
    G[fr].push_back(Edge(to, i));
  }
  for (int i = 0; i < totNodes; i++)
    if (inque[i] == -1) Dfs(i);
  puts(cyc ? "2" : "1");
  for (int i = 0; i < totEdges; i++) printf("%d ", color[i]);
  putchar('\n');
  return 0;
}
