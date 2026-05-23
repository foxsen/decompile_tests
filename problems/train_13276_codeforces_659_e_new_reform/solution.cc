#include <bits/stdc++.h>
using namespace std;
int N, M;
bool group[100001];
bool trip[100001];
vector<int> Map[100001];
bool flag;
void search(int v, int par) {
  group[v] = true;
  trip[v] = true;
  for (int i = 0; i < Map[v].size(); i++) {
    int now = Map[v][i];
    if (now == par) continue;
    if (trip[now]) flag = true;
    if (!group[now]) search(now, v);
  }
  trip[v] = false;
}
int main() {
  scanf("%d%d", &N, &M);
  int a, b;
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &a, &b);
    Map[a].push_back(b);
    Map[b].push_back(a);
  }
  int ans = 0;
  for (int i = 1; i <= N; i++)
    if (!group[i]) {
      flag = false;
      search(i, 0);
      if (!flag) ans++;
    }
  printf("%d\n", ans);
  return 0;
}
