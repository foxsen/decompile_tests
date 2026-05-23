#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
int n, m, cnt;
int deg[1000000 + 7];
bool visit[1000000 + 7];
vector<int> edges[1000000 + 7];
vector<int> odd;
void reset() {
  int i, lim = n + 2;
  for (i = 0; i < lim; i++) {
    edges[i].clear();
    visit[i] = deg[i] = 0;
  }
  odd.clear();
}
int dfs(int u) {
  int sz, v, ret = 0, i, j;
  sz = edges[u].size();
  cnt++;
  for (i = 0; i < sz; i++) {
    v = edges[u][i];
    if (!visit[v]) {
      visit[v] = 1;
      ret += dfs(v);
    }
  }
  return ret + (deg[u] % 2);
}
int main() {
  int u, v, ans, sz, cur, ret, i, j, k;
  while (scanf("%d %d", &n, &m) == 2) {
    reset();
    ans = 0;
    for (i = 0; i < m; i++) {
      scanf("%d %d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
      deg[u]++;
      deg[v]++;
    }
    visit[1] = 1;
    odd.push_back(dfs(1));
    for (i = 2; i <= n; i++) {
      if (!visit[i]) {
        visit[i] = 1;
        if (edges[i].size() == 0) continue;
        ret = dfs(i);
        odd.push_back(ret);
      }
    }
    sz = odd.size();
    if (sz) {
      cur = odd[0];
      for (i = 1; i < sz; i++) {
        if (cur == odd[i] and cur == 0) {
          cur += 2;
          ans++;
        } else if (cur and odd[i]) {
          cur += odd[i];
          cur -= 2;
          ans++;
        } else if (cur == 0 and odd[i]) {
          cur += odd[i];
          ans++;
        } else if (odd[i] == 0 and cur) {
          ans++;
        }
      }
      ans += (cur / 2);
    }
    printf("%d\n", ans);
  }
  return 0;
}
