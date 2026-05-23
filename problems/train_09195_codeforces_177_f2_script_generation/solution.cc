#include <bits/stdc++.h>
using namespace std;
clock_t __stt;
inline void TStart() { __stt = clock(); }
inline void TReport() {
  printf("\nTaken Time : %.3lf sec\n",
         (double)(clock() - __stt) / CLOCKS_PER_SEC);
}
template <typename T>
T MIN(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
T MAX(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
T ABS(T a) {
  return a > 0 ? a : (-a);
}
template <typename T>
void UMIN(T &a, T b) {
  if (b < a) a = b;
}
template <typename T>
void UMAX(T &a, T b) {
  if (b > a) a = b;
}
int n, m, T;
pair<pair<int, int>, int> es[105];
priority_queue<pair<int, pair<int, int> > > pq;
int main() {
  int i, j, k;
  scanf("%d%d%d", &n, &m, &T);
  for (i = 0; i < m; ++i) {
    scanf("%d%d%d", &es[i].first.first, &es[i].first.second, &es[i].second);
    --es[i].first.first;
    --es[i].first.second;
  }
  sort(es, es + m);
  pq.push(make_pair(0, make_pair(0, 0)));
  while (T--) {
    int l = pq.top().second.first, r = pq.top().second.second,
        c = -pq.top().first;
    pq.pop();
    if (!T) printf("%d\n", c);
    for (i = 0; i < m; ++i) {
      int u = es[i].first.first, v = es[i].first.second, w = es[i].second;
      if (!(l & (1 << u)) && !(r & (1 << v))) {
        pq.push(make_pair(-c - w, make_pair(l | (1 << u), r | (1 << v))));
      }
      if (i < m - 1 && u != es[i + 1].first.first) l |= (1 << u);
    }
  }
  return 0;
}
