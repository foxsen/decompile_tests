#include <bits/stdc++.h>
using namespace std;
set<pair<long long, long long> > s;
pair<long long, long long> a[300000], b[300000];
int num = 0, n, p[300000], A[300000], B[300000];
void ConvexHull() {
  int cnt = 0;
  for (int i = 1; i <= num; i++) {
    pair<long long, long long> u = b[i];
    while (cnt > 1 &&
           ((b[p[cnt]].first - b[p[cnt - 1]].first) *
                (b[p[cnt]].second - u.second) * u.first * b[p[cnt - 1]].second <
            (b[p[cnt - 1]].second - b[p[cnt]].second) *
                (u.first - b[p[cnt]].first) * b[p[cnt - 1]].first * u.second))
      cnt--;
    p[++cnt] = i;
  }
  for (int i = 1; i <= cnt; i++) s.insert(b[p[i]]);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &A[i], &B[i]), a[i] = make_pair(A[i], B[i]);
  sort(a + 1, a + n + 1);
  int Min = -1;
  for (int i = n; i >= 1; i--)
    if (a[i].second > Min) Min = a[i].second, b[++num] = a[i];
  reverse(b + 1, b + num + 1);
  ConvexHull();
  for (int i = 1; i <= n; i++)
    if (s.count(make_pair(A[i], B[i]))) printf("%d ", i);
  return 0;
}
