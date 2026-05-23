#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:20000000")
int n;
char s[200005];
int a[200005];
bool v[200005];
int l[200005], r[200005];
priority_queue<pair<int, pair<int, int> > > q;
vector<pair<int, int> > res;
int main() {
  scanf("%d\n", &n);
  gets(s);
  for (int i = 0; i < (n); ++i) scanf("%d", &a[i]);
  for (int i = 0; i < (n - 1); ++i) {
    if (s[i] != s[i + 1])
      q.push(make_pair(-abs(a[i] - a[i + 1]), make_pair(-i, -i - 1)));
  }
  for (int i = 0; i < (n); ++i) {
    l[i] = i - 1;
    r[i] = i + 1;
  }
  while (!q.empty()) {
    pair<int, int> w = q.top().second;
    q.pop();
    int x = -w.first;
    int y = -w.second;
    if (v[x] || v[y]) continue;
    v[x] = v[y] = 1;
    res.push_back(make_pair(x, y));
    if (l[x] >= 0) r[l[x]] = r[y];
    if (l[y] >= 0) l[r[y]] = l[x];
    if (l[x] >= 0 && r[y] < n)
      if (s[l[x]] != s[r[y]]) {
        q.push(make_pair(-abs(a[l[x]] - a[r[y]]), make_pair(-l[x], -r[y])));
      }
  }
  n = res.size();
  printf("%d\n", n);
  for (int i = 0; i < (n); ++i)
    printf("%d %d\n", res[i].first + 1, res[i].second + 1);
  return 0;
}
