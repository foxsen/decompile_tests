#include <bits/stdc++.h>
const int N = 1001010;
using namespace std;
int Next[N], Pre[N], id[N], a[N], i, j, n, tmp, vis[N];
long long ans;
bool cmp(int x, int y) { return a[x] < a[y]; }
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d", &a[i]), id[i] = i, Next[i] = i + 1, Pre[i] = i - 1;
  sort(id + 1, id + 1 + n, cmp);
  for (i = 1; i <= n; i++)
    if ((id[i] != 1) && (id[i] != n)) {
      tmp = min(a[Pre[id[i]]], a[Next[id[i]]]);
      if (tmp >= a[id[i]]) {
        ans += tmp;
        Next[Pre[id[i]]] = Next[id[i]];
        Pre[Next[id[i]]] = Pre[id[i]];
      } else
        vis[i] = 1;
    }
  int t1 = 1, t2 = n;
  for (i = n; i >= 1; i--)
    if (vis[i]) {
      if (t1 == 1)
        t1 = id[i];
      else if (t2 == n)
        t2 = id[i];
    }
  if (t1 > t2) t1 ^= t2 ^= t1 ^= t2;
  while ((t1 != 1) || (t2 != n)) {
    if ((t1 == 1) ||
        (min(a[Pre[t2]], a[Next[t2]]) > min(a[Pre[t1]], a[Next[t1]]))) {
      ans += min(a[Pre[t2]], a[Next[t2]]);
      Pre[Next[t2]] = Pre[t2];
      Next[Pre[t2]] = Next[t2];
      t2 = Next[t2];
    } else {
      ans += min(a[Pre[t1]], a[Next[t1]]);
      Pre[Next[t1]] = Pre[t1];
      Next[Pre[t1]] = Next[t1];
      t1 = Pre[t1];
    }
  }
  printf("%I64d\n", ans);
}
