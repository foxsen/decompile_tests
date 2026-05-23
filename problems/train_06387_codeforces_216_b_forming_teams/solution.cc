#include <bits/stdc++.h>
using namespace std;
int N, M;
int p[101];
int e[101];
int res = 0;
int FindSet(int x);
int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) p[i] = i, e[i] = 1;
  int x, y;
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &x, &y);
    int px = FindSet(x), py = FindSet(y);
    if ((px == py) && (e[py] & 1)) res++;
    p[px] = p[y];
    e[py] += e[px];
  }
  if ((N - res) % 2 != 0) res++;
  cout << res;
  return 0;
}
int FindSet(int x) {
  if (x != p[x]) return FindSet(p[x]);
  return x;
}
