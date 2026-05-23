#include <bits/stdc++.h>
int take() {
  int n;
  scanf("%d", &n);
  return n;
}
double ttake() {
  double n;
  scanf("%lf", &n);
  return n;
}
long long takes() {
  long long n;
  scanf("%lld", &n);
  return n;
}
int cas;
using namespace std;
bool approximatelyEqual(float a, float b, float epsilon) {
  return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
bool essentiallyEqual(float a, float b, float epsilon) {
  return fabs(a - b) <= ((fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
bool definitelyGreaterThan(float a, float b, float epsilon) {
  return (a - b) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
bool definitelyLessThan(float a, float b, float epsilon) {
  return (b - a) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
vector<pair<int, int> > d;
bool nw[200005];
vector<int> v1[200005], canAdd[200005];
int in[200005];
int save[200005];
void bfs(int n, int k) {
  queue<pair<int, pair<int, int> > > q;
  if (d[n - 1].first != 0) {
    printf("-1");
    return;
  }
  q.push(make_pair(0, make_pair(d[n - 1].second, -1)));
  d.pop_back();
  int ans = 0;
  pair<int, int> res[200005 + 1];
  while (!q.empty()) {
    pair<int, pair<int, int> > p = q.front();
    q.pop();
    int x = p.first, y = p.second.first, par = p.second.second;
    if (nw[y]) continue;
    if (par != -1 && in[par] < k && in[y] < k) {
      v1[par].push_back(y);
      res[++ans] = make_pair(par, y);
      in[par]++, in[y]++;
      nw[y] = 1;
    } else if (par != -1)
      continue;
    int ok = 0;
    nw[y] = 1;
    while (!d.empty()) {
      if (in[y] + ok >= k) break;
      if (d.back().first == x + 1) {
        q.push(make_pair(x + 1, make_pair(d.back().second, y)));
        d.pop_back();
        ok++;
      } else {
        break;
      }
    }
  }
  for (int i = 1; i <= n; i += 1) {
    if (nw[i]) {
      if (in[i] != k) canAdd[save[i]].push_back(i);
    }
  }
  for (int i = 1; i <= n; i += 1) {
    if (!nw[i]) {
      if (canAdd[save[i] - 1].empty()) {
        printf("-1");
        return;
      }
      res[++ans] = make_pair(canAdd[save[i] - 1].back(), i);
      in[canAdd[save[i] - 1].back()]++;
      nw[i] = 1;
      if (in[canAdd[save[i] - 1].back()] >= k) canAdd[save[i] - 1].pop_back();
    }
  }
  for (int i = 1; i <= n; i += 1) {
    if (!nw[i]) {
      printf("-1");
      return;
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i += 1)
    printf("%d %d\n", res[i].first, res[i].second);
}
int main() {
  int tc = 1;
  while (tc--) {
    int n = take(), k = take();
    for (int i = 1; i <= n; i += 1) {
      int u = take();
      save[i] = u;
      d.push_back(make_pair(u, i));
    }
    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());
    bfs(n, k);
  }
  { return 0; };
}
