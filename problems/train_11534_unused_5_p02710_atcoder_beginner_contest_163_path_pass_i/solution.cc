#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdint>

int const MAXN = 2e5;
int c[MAXN];
std::vector<int> G[MAXN];
int N;
int64_t ans[MAXN];
int nn[MAXN], csum[MAXN];

void dfs(int v, int p) {
  int cv = c[v], save = csum[cv], nodes = 1;
  for(auto ch: G[v]) if(ch != p) {
    int pcsum = csum[cv];
    dfs(ch, v);
    int dcsum = csum[cv] - pcsum;
    int w = nn[ch] - dcsum;
    ans[cv] -= (int64_t)w*(w+1)/2;
    nodes += nn[ch];
  }
  csum[cv] = save + (nn[v] = nodes);
}

int main() {
  std::cin >> N;
  for(int i = 0; i < N; ++i) { std::cin >> c[i]; --c[i]; }
  for(int i = 0; i < N-1; ++i) {
    int a, b; std::cin >> a >> b; --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  std::fill_n(ans, N, (int64_t)N*(N+1)/2);
  dfs(0, -1);
  for(int i = 0; i < N; ++i) {
    int w = N - csum[i];
    ans[i] -= (int64_t)w*(w+1)/2;
  }
  for(int i = 0; i < N; ++i) std::cout << ans[i] << std::endl;
  return 0;
}
