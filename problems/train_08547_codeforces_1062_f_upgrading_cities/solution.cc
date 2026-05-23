#include <bits/stdc++.h>
using namespace std;
const int N = 300010, M = 5 * 300000;
int n, m, val[N], in[N], u, v, idx[N], cnt = 0, cur = 0, tmpin[N], ans = 0,
                                       node, arr[N], seg[4 * N], num[N],
                                       arr2[N];
vector<int> g[N];
int A[N], B[N];
priority_queue<pair<int, int> > q;
bool awwal = true;
int Idx;
inline int update(int s, int e, int idx) {
  if (s > Idx || e < Idx) return seg[idx];
  if (s == e) return seg[idx] = 1;
  return seg[idx] = update(s, ((s + e) >> 1), (idx << 1)) +
                    update(((s + e) >> 1) + 1, e, (idx << 1) + 1);
}
int l, r;
inline int getsum(int s, int e, int idx) {
  if (s > r || e < l) return 0;
  if (s >= l && e <= r) return seg[idx];
  return getsum(s, ((s + e) >> 1), (idx << 1)) +
         getsum(((s + e) >> 1) + 1, e, (idx << 1) + 1);
}
int tmp;
inline int get(int s, int e, int idx) {
  if (s > r || e < l || seg[idx] == 0) return -1;
  if (s == e) return arr2[s];
  int tmp = get(s, ((s + e) >> 1), (idx << 1));
  if (tmp != -1) return tmp;
  return get(((s + e) >> 1) + 1, e, (idx << 1) + 1);
}
inline void top_sort() {
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    tmpin[i] = in[i];
    if (tmpin[i] == 0) q.push(make_pair(val[i], i));
  }
  while (!q.empty()) {
    node = q.top().second;
    q.pop();
    idx[node] = cnt++;
    arr2[cnt - 1] = node;
    if (awwal) arr[cnt - 1] = node;
    for (int i = 0; i < (int)g[node].size(); i++) {
      tmpin[g[node][i]]--;
      if (tmpin[g[node][i]] == 0) {
        q.push(make_pair(val[g[node][i]], g[node][i]));
      }
    }
  }
  if (awwal) {
    awwal = false;
    return;
  }
  for (int i = 0; i <= 4 * n; i++) seg[i] = 0;
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      Idx = idx[arr[i - 1]];
      update(0, n - 1, 1);
    }
    if (num[arr[i]] > 1) continue;
    l = idx[arr[i]], r = n - 1;
    cur = getsum(0, n - 1, 1);
    if (cur > 1) {
      num[arr[i]] = 2;
      continue;
    }
    if (cur == 0) continue;
    cur = get(0, n - 1, 1);
    if (A[arr[i]] == -1)
      A[arr[i]] = cur;
    else if (A[arr[i]] != cur)
      B[arr[i]] = cur;
    num[arr[i]] = (A[arr[i]] != -1) + (B[arr[i]] != -1);
  }
  for (int i = 0; i <= 4 * n; i++) seg[i] = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i != n - 1) {
      Idx = idx[arr[i + 1]];
      update(0, n - 1, 1);
    }
    if (num[arr[i]] > 1) continue;
    r = idx[arr[i]], l = 0;
    cur = getsum(0, n - 1, 1);
    if (cur > 1) {
      num[arr[i]] = 2;
      continue;
    }
    if (cur == 0) continue;
    cur = get(0, n - 1, 1);
    if (A[arr[i]] == -1)
      A[arr[i]] = cur;
    else if (A[arr[i]] != cur)
      B[arr[i]] = cur;
    num[arr[i]] = (A[arr[i]] != -1) + (B[arr[i]] != -1);
  }
}
int main() {
  srand(time(0));
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    in[v]++;
  }
  for (int i = 1; i <= n; i++) val[i] = i, A[i] = B[i] = -1, num[i] = 0;
  for (int it = 0; it < min(20, M / n); it++) {
    for (int j = 0; j < 10; j++) random_shuffle(val, val + n);
    top_sort();
    for (int i = 1; i <= n; i++) val[i] = idx[i];
    top_sort();
  }
  for (int i = 1; i <= n; i++) {
    if (num[i] < 2) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
