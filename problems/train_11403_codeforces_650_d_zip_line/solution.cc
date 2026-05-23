#include <bits/stdc++.h>
using namespace std;
const int N = 400000 + 5;
const int INF = 1e9 + 7;
int ht[N];
vector<pair<int, int> > adj[N];
int ans[N];
int lis[N], lds[N];
int fl[N], fr[N];
int grp[N], freq[N];
inline int findlis(int l, int r, int v) {
  int mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (v <= lis[mid])
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
inline int findlds(int l, int r, int v) {
  int mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (v >= lds[mid])
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
int main(int argc, char const *argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ht[i]);
    lis[i] = INF, lds[i] = 0;
  }
  int a, b;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &a, &b);
    adj[a].push_back((pair<int, int>){b, i});
  }
  int len = 0;
  for (int i = 1; i <= n; i++) {
    for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
      ans[it->second] += findlis(1, n, it->first);
    }
    lis[fl[i] = findlis(1, n, ht[i])] = ht[i];
    len = max(len, fl[i]);
  }
  for (int i = n; i >= 1; i--) {
    for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
      ans[it->second] += findlds(1, n, it->first);
    }
    lds[fr[i] = findlds(1, n, ht[i])] = ht[i];
    if (fl[i] + fr[i] - 1 == len) {
      freq[fl[i]]++;
    } else {
      grp[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (grp[i] == 1) continue;
    if (freq[fl[i]] == 1)
      grp[i] = 3;
    else
      grp[i] = 2;
  }
  int p;
  for (int i = 1; i <= n; i++) {
    for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
      p = it->second;
      ans[p]--;
      if (grp[i] == 1) {
        ans[p] = max(ans[p], len);
      } else if (grp[i] == 2) {
        ans[p] = max(ans[p], len);
      } else {
        ans[p] = max(ans[p], len - 1);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
