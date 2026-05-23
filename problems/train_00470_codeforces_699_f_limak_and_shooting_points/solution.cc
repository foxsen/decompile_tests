#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
struct point {
  int first, second;
  point(int first = 0, int second = 0) : first(first), second(second) {}
  point operator-(point a) { return point(first - a.first, second - a.second); }
  long long operator^(point a) {
    return (long long)first * a.second - (long long)second * a.first;
  }
  long long operator*(point a) {
    return (long long)first * a.first + (long long)second * a.second;
  }
  void input() { scanf("%d%d", &first, &second); }
};
int sgn(long long a) { return (a > 0) - (a < 0); }
int is_on(point a, point b, point c) {
  if (sgn((a - b) ^ (a - c))) return 0;
  return sgn((a - c) * (c - b)) > 0;
}
point ston[1110], mon[1110];
int id[10], vst[1110], runs, used, k, n;
vector<int> adj[10][1110];
bool judge(int u) {
  vst[u] = runs;
  if (used >= k) return false;
  int tmp = id[used++];
  for (int i = 0; i < adj[tmp][u].size(); i++) {
    int v = adj[tmp][u][i];
    if (vst[v] != runs)
      if (!judge(v)) return false;
  }
  return true;
}
int main() {
  scanf("%d%d", &k, &n);
  for (int i = 0; i < k; i++) ston[i].input();
  for (int i = 0; i < n; i++) mon[i].input();
  for (int i = 0; i < k; i++) {
    for (int p = 0; p < n; p++) {
      for (int j = 0; j < n; j++)
        if (j != p) {
          if (is_on(ston[i], mon[p], mon[j])) adj[i][p].push_back(j);
          if (adj[i][p].size() >= k) break;
        }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) id[j] = j;
    do {
      ++runs;
      used = 0;
      if (judge(i)) {
        res++;
        break;
      }
    } while (next_permutation(id, id + k));
  }
  printf("%d\n", res);
  return 0;
}
