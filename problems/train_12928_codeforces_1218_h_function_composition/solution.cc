#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 234;
vector<pair<int, int> > arpa[N], pasha[N];
int mark[N], cmp[N], plCycl[N], Next[N];
int st[N], en[N], hei[N], now;
vector<int> Prev[N], cycles[N], height[N];
int goPrev(int x, long long n) {
  int cLen = ((int)cycles[cmp[x]].size());
  n = cLen - (n % cLen);
  return cycles[cmp[x]][(plCycl[x] + n) % cLen];
}
int goNext(int x, int cnt, int first) {
  mark[x] = first;
  if (mark[Next[x]] != first and mark[Next[x]] != -1) return 0;
  if (mark[Next[x]] == first) {
    int now = x;
    while (true) {
      plCycl[now] = ((int)cycles[cnt].size());
      cycles[cnt].push_back(now);
      cmp[now] = cnt;
      if (Next[now] == x) break;
      now = Next[now];
    }
    return 1;
  }
  return goNext(Next[x], cnt, first);
}
void dfs(int x, int root, int h = 0) {
  st[x] = now++;
  height[h].push_back(st[x]);
  hei[x] = h;
  arpa[goPrev(root, h)].push_back({h, 1});
  for (auto u : Prev[x])
    if (cmp[u] == -1) dfs(u, root, h + 1);
  en[x] = now;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  memset(mark, -1, sizeof mark);
  memset(cmp, -1, sizeof cmp);
  int n, q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    t--;
    Next[i] = t;
    Prev[t].push_back(i);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (mark[i] == -1) cnt += goNext(i, cnt, i);
  for (int i = 0; i < n; i++) {
    if (cmp[i] != -1) dfs(i, i);
  }
  for (int i = 0; i < n; i++)
    if (cmp[i] != -1) {
      sort(arpa[i].begin(), arpa[i].end());
      for (int j = 0; j < ((int)arpa[i].size()); j++)
        if (j < ((int)arpa[i].size()) - 1 and
            arpa[i][j].first == arpa[i][j + 1].first)
          arpa[i][j + 1].second += arpa[i][j].second;
        else
          pasha[i].push_back(
              {arpa[i][j].first,
               arpa[i][j].second +
                   (((int)pasha[i].size()) ? pasha[i].back().second : 0)});
    }
  cin >> q;
  while (q--) {
    long long m, x;
    cin >> m >> x;
    x--;
    if (cmp[x] != -1) {
      int root = goPrev(x, m);
      auto it = upper_bound(pasha[root].begin(), pasha[root].end(),
                            pair<int, int>(min<long long>(m, N), N));
      it--;
      cout << (*it).second << '\n';
    } else {
      if (m + hei[x] >= N)
        cout << 0 << '\n';
      else
        cout << lower_bound(height[hei[x] + m].begin(),
                            height[hei[x] + m].end(), en[x]) -
                    lower_bound(height[hei[x] + m].begin(),
                                height[hei[x] + m].end(), st[x])
             << '\n';
    }
  }
  return 0;
}
