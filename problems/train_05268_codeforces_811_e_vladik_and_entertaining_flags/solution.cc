#include <bits/stdc++.h>
using namespace std;
const int N = 100050;
const int M = 2 * N;
int n, m;
int mat[N][10];
struct Node {
  int sol, ss, se;
  int lid[10], rid[10], nid;
  Node() {}
} node[M];
struct DSU {
  int p[40];
  DSU() {}
  void init() {
    for (int i = 0; i < 40; i++) p[i] = i;
  }
  int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
  void Union(int x, int y) { p[Find(x)] = Find(y); }
} Tree;
Node Merge(Node a, Node b) {
  Node ans;
  ans.sol = a.sol + b.sol;
  ans.ss = a.ss;
  ans.se = b.se;
  ans.nid = a.nid + b.nid;
  int l = a.se, r = b.ss;
  for (int i = 0; i < n; i++) b.lid[i] += a.nid, b.rid[i] += a.nid;
  for (int i = 0; i < n; i++)
    if (a.rid[i] != b.lid[i] && mat[l][i] == mat[r][i]) {
      ans.sol--;
      int oid = b.lid[i];
      for (int j = 0; j < n; j++)
        if (a.lid[j] == oid) a.lid[j] = a.rid[i];
      for (int j = 0; j < n; j++)
        if (a.rid[j] == oid) a.rid[j] = a.rid[i];
      for (int j = 0; j < n; j++)
        if (b.lid[j] == oid) b.lid[j] = a.rid[i];
      for (int j = 0; j < n; j++)
        if (b.rid[j] == oid) b.rid[j] = a.rid[i];
    }
  for (int i = 0; i < n; i++) ans.lid[i] = a.lid[i], ans.rid[i] = b.rid[i];
  return ans;
}
int ls[M], rs[M], tsz, root;
void Build(int &c, int ss, int se) {
  c = ++tsz;
  if (ss == se) {
    int i, j;
    node[c].ss = node[c].se = ss;
    node[c].sol = node[c].nid = 0;
    for (i = 0; i < n; i = j) {
      for (j = i; j < n && mat[ss][j] == mat[ss][i]; j++)
        node[c].lid[j] = node[c].rid[j] = node[c].nid;
      node[c].nid++;
      node[c].sol++;
    }
    return;
  }
  int mid = ss + se >> 1;
  Build(ls[c], ss, mid);
  Build(rs[c], mid + 1, se);
  node[c] = Merge(node[ls[c]], node[rs[c]]);
}
Node Get(int c, int ss, int se, int qs, int qe) {
  if (qs <= ss && qe >= se) return node[c];
  int mid = ss + se >> 1;
  if (qe <= mid) return Get(ls[c], ss, mid, qs, qe);
  if (qs > mid) return Get(rs[c], mid + 1, se, qs, qe);
  return Merge(Get(ls[c], ss, mid, qs, qe), Get(rs[c], mid + 1, se, qs, qe));
}
int main() {
  int q, i, j, l, r;
  scanf("%i %i %i", &n, &m, &q);
  for (i = 0; i < n; i++)
    for (j = 1; j <= m; j++) scanf("%i", &mat[j][i]);
  Build(root, 1, m);
  while (q--) {
    scanf("%i %i", &l, &r);
    Node ans = Get(root, 1, m, l, r);
    printf("%i\n", ans.sol);
  }
  return 0;
}
