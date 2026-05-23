#include <bits/stdc++.h>
using namespace std;
struct record {
  long long x, y;
  bool operator<(const record &b) const { return x == b.x ? y > b.y : x < b.x; }
  record() {}
  record(long long _x, long long _y) {
    x = _x;
    y = _y;
  }
};
vector<long long> p[10010];
long long a[100010];
long long c[100010];
long long d[10010];
priority_queue<record> q;
long long newk[100010];
long long cnt = 0;
long long h, n, m, k;
bool cmp(long long i, long long j) { return a[i] < a[j]; }
void spfa() {
  queue<long long> bfs;
  bool flag[10010];
  for (long long i = 0; i < k; i++)
    if (d[i] < 1e18 + 100) {
      bfs.push(i);
      flag[i] = true;
    } else
      flag[i] = false;
  while (!bfs.empty()) {
    long long now = bfs.front();
    bfs.pop();
    flag[now] = false;
    for (long long i = 0; i < cnt; i++) {
      long long next = d[now] + newk[i];
      long long y = next % k;
      if (next < d[y]) {
        d[y] = next;
        if (!flag[y]) {
          bfs.push(y);
          flag[y] = true;
        }
      }
    }
  }
  for (long long i = 0; i < k; i++)
    while (p[i].size() > 0 && a[p[i][p[i].size() - 1]] >= d[i]) {
      q.push(record(c[p[i][p[i].size() - 1]], p[i][p[i].size() - 1]));
      p[i].pop_back();
    }
}
int main() {
  cin >> h >> n >> m >> k;
  for (long long i = 0; i < n; i++) {
    cin >> a[i] >> c[i];
    a[i]--;
    p[a[i] % k].push_back(i);
  }
  for (long long i = 0; i < k; i++) {
    sort(p[i].begin(), p[i].end(), cmp);
    d[i] = 1e18 + 100;
  }
  d[0] = 0;
  spfa();
  while (m--) {
    long long op;
    cin >> op;
    if (op == 1) {
      cin >> newk[cnt++];
      spfa();
    } else if (op == 2) {
      long long x, y;
      cin >> x >> y;
      x--;
      c[x] -= y;
      if (d[a[x] % k] <= a[x]) q.push(record(c[x], x));
    } else if (op == 3) {
      while (!q.empty() && q.top().x != c[q.top().y]) q.pop();
      if (!q.empty()) {
        cout << q.top().x << endl;
        c[q.top().y] = 0;
        q.pop();
      } else
        cout << 0 << endl;
    }
  }
  return 0;
}
