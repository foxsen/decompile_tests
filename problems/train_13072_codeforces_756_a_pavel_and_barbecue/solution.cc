#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
const int inf = 1e9 + 50;
const int mod = 1e9 + 7;
int read() {
  int k = 0, sig = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') sig *= -1;
    c = getchar();
  }
  while (isdigit(c)) {
    k = (k << 3) + (k << 1) + c - '0';
    c = getchar();
  }
  return k * sig;
}
int main() {
  vector<vector<int>> v(N);
  vector<int> siz(N, 0), st(N);
  int n = read();
  for (int i = 1; i <= n; i++) {
    int w = read();
    v[i].push_back(w);
  }
  int num = 0;
  for (int i = 1; i <= n; i++) num += read();
  int cnt = 1;
  std::function<void(int)> dfs = [&](int x) {
    siz[cnt]++;
    st[x] = cnt;
    for (auto y : v[x]) {
      if (st[y]) continue;
      dfs(y);
    }
  };
  bool ok = false, okk = false;
  int ans = 0;
  dfs(1);
  for (int i = 1; i <= n; i++) {
    if (st[i]) continue;
    ++cnt;
    dfs(i);
    okk = true;
    ans++;
  }
  printf("%d", ans + okk + (num % 2 ? 0 : 1));
}
