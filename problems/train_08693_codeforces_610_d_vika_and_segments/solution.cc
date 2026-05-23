#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n;
set<int> compr;
int cnt;
map<int, int> f;
map<int, vector<pair<int, int> > > row;
map<int, vector<pair<int, int> > > col;
map<int, vector<pair<int, pair<int, int> > > > e;
long long ans;
const int MAXN = 4 * N;
long long tree[MAXN];
long long query(int idx) {
  long long sum = 0;
  while (idx) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}
void update(int idx, int val) {
  while (idx < MAXN) {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}
bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
  if (p1.first == p2.first) return p1.second > p2.second;
  return p1.first < p2.first;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d", &x1, &y1);
    scanf("%d%d", &x2, &y2);
    if (x1 == x2) {
      if (y1 > y2) swap(y1, y2);
      col[x1].push_back(make_pair(y1, y2));
    } else {
      if (x1 > x2) swap(x1, x2);
      row[y1].push_back(make_pair(x1, x2));
    }
    compr.insert(x1);
    compr.insert(x2);
    compr.insert(y1);
    compr.insert(y2);
  }
  for (__typeof(compr.begin()) it(compr.begin()); it != compr.end(); it++) {
    f[*it] = ++cnt;
  }
  for (__typeof(row.begin()) it(row.begin()); it != row.end(); it++) {
    vector<pair<int, int> > &v1 = it->second;
    vector<pair<int, int> > v2;
    sort(v1.begin(), v1.end(), comp);
    pair<int, int> cur = v1[0];
    for (int i = 1; i < v1.size(); i++) {
      if (v1[i].first > cur.second) {
        v2.push_back(cur);
        cur = v1[i];
      } else {
        cur.second = max(cur.second, v1[i].second);
      }
    }
    v2.push_back(cur);
    it->second = v2;
    for (__typeof(v2.begin()) seg(v2.begin()); seg != v2.end(); seg++) {
      ans += 1ll * (seg->second - seg->first + 1);
      e[seg->first].push_back(make_pair(1, make_pair(it->first, -1)));
      e[seg->second + 1].push_back(make_pair(2, make_pair(it->first, -1)));
    }
  }
  for (__typeof(col.begin()) it(col.begin()); it != col.end(); it++) {
    vector<pair<int, int> > &v1 = it->second;
    vector<pair<int, int> > v2;
    sort(v1.begin(), v1.end(), comp);
    pair<int, int> cur = v1[0];
    for (int i = 1; i < v1.size(); i++) {
      if (v1[i].first > cur.second) {
        v2.push_back(cur);
        cur = v1[i];
      } else {
        cur.second = max(cur.second, v1[i].second);
      }
    }
    v2.push_back(cur);
    it->second = v2;
    for (__typeof(v2.begin()) seg(v2.begin()); seg != v2.end(); seg++) {
      e[it->first].push_back(make_pair(3, make_pair(seg->first, seg->second)));
    }
  }
  for (__typeof(e.begin()) it(e.begin()); it != e.end(); it++) {
    vector<pair<int, pair<int, int> > > &v = it->second;
    for (__typeof(v.begin()) event(v.begin()); event != v.end(); event++) {
      if (event->first == 1) {
        update(f[event->second.first], 1);
      } else if (event->first == 2) {
        update(f[event->second.first], -1);
      } else {
        long long b = event->second.second, a = event->second.first;
        long long len = b - a + 1;
        len -= query(f[b]) - query(f[a] - 1);
        ans += len;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
