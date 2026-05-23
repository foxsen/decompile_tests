#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool debug = false;
int W;
struct root {
  int id;
  long long edge, ss;
  vector<int> subNodes;
};
vector<pair<int, long long>> mp[200005];
vector<root> rs;
int v[200005];
int cpoint[200005];
long long sumNode[200005], countNode[200005], dd[200005],
    toOtherFromFAther[200005], ans[200005];
root *rr;
int findCircle(int i, int p) {
  if (v[i]) return i;
  v[i] = 1;
  for (vector<pair<int, long long>>::iterator it = mp[i].begin();
       it != mp[i].end(); it++) {
    int w = it->first;
    if (w == p) continue;
    int t = findCircle(w, i);
    if (t != -1) {
      cpoint[w] = 1;
      root r;
      r.id = w;
      r.edge = it->second;
      rs.push_back(r);
      return t == i ? -1 : t;
    }
  }
  return -1;
}
void dfs(int i, int p) {
  rr->subNodes.push_back(i);
  sumNode[i] = 0;
  countNode[i] = 1;
  for (vector<pair<int, long long>>::iterator it = mp[i].begin();
       it != mp[i].end(); it++) {
    int w = it->first;
    if (w == p || cpoint[w]) continue;
    dd[w] += dd[i] + it->second;
    dfs(w, i);
    countNode[i] += countNode[w];
    sumNode[i] += sumNode[w] + it->second * countNode[w];
  }
}
void dfs1(int i, int p) {
  for (vector<pair<int, long long>>::iterator it = mp[i].begin();
       it != mp[i].end(); it++) {
    int w = it->first;
    if (w == p || cpoint[w]) continue;
    toOtherFromFAther[w] = toOtherFromFAther[i] + sumNode[i] - sumNode[w] -
                           it->second * countNode[w] +
                           it->second * (countNode[rr->id] - countNode[w]);
    dfs1(w, i);
  }
}
void calTree(int i) {
  rr = &rs[i];
  dd[rr->id] = 0;
  dfs(rr->id, -1);
  toOtherFromFAther[rr->id] = 0;
  dfs1(rr->id, -1);
  for (vector<int>::iterator it = rr->subNodes.begin();
       it != rr->subNodes.end(); it++) {
    ans[*it] = sumNode[*it] + toOtherFromFAther[*it];
  }
  rr->ss = ans[rr->id];
}
void calCircle() {
  long long cursum = 0, cnt = 0, cirlen = 0, sum = 0;
  int q = 0;
  long long ee[200005 + 200005];
  for (int i = 0; i < m; i++) {
    cirlen += rs[i].edge;
    sum += rs[i].ss;
    ee[i + 1 + m] = ee[i + 1] = rs[i].edge;
  }
  ee[0] = 0;
  partial_sum(ee, ee + m + m + 1, ee);
  while (2 * (ee[q] - ee[0]) <= cirlen) {
    cursum += (ee[q] - ee[0]) * countNode[rs[q].id];
    cnt += countNode[rs[q].id];
    q++;
  }
  for (int i = q; i < m; i++) {
    cursum += (cirlen - (ee[i] - ee[0])) * countNode[rs[i].id];
  }
  for (int i = 0; i < m; i++) {
    while (2 * (ee[q] - ee[i]) <= cirlen) {
      cursum = cursum - (cirlen - (ee[q] - ee[i])) * countNode[rs[q % m].id] +
               (ee[q] - ee[i]) * countNode[rs[q % m].id];
      cnt += countNode[rs[q % m].id];
      q++;
    }
    for (vector<int>::iterator it = rs[i].subNodes.begin();
         it != rs[i].subNodes.end(); it++) {
      ans[*it] += sum - rs[i].ss + cursum + dd[*it] * (n - countNode[rs[i].id]);
    }
    cnt -= countNode[rs[i].id];
    cursum += (n - cnt) * rs[i].edge;
    cursum -= cnt * rs[i].edge;
  }
}
int main() {
  scanf("%d", &n);
  int a, b, t;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &a, &b, &t);
    a--;
    b--;
    mp[a].push_back(make_pair(b, t));
    mp[b].push_back(make_pair(a, t));
  }
  findCircle(0, -1);
  m = (int)rs.size();
  for (int i = 0; i < m; i++) {
    calTree(i);
  }
  calCircle();
  for (int i = 0; i < n; i++) {
    printf("%I64d ", ans[i]);
  }
  return 0;
}
