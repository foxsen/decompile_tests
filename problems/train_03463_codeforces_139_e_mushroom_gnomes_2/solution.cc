#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[100005 * 4 + 10005], num[100005 * 4 + 10005], cnt;
double p[100005 * 4 + 10005];
struct Tree {
  int w, l, r, h;
} data[100005];
struct Mushroom {
  int w, z;
} mush[10005];
int find(int w) {
  int g = 0, h = cnt - 1;
  while (g <= h) {
    int mid = (g + h) / 2;
    if (x[mid] == w)
      return mid;
    else if (x[mid] < w)
      g = mid + 1;
    else
      h = mid - 1;
  }
  while (1)
    ;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &data[i].w, &data[i].h, &data[i].l, &data[i].r);
    x[cnt++] = data[i].w + 1;
    x[cnt++] = data[i].w;
    x[cnt++] = data[i].w - data[i].h;
    x[cnt++] = data[i].w + data[i].h + 1;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &mush[i].w, &mush[i].z);
    x[cnt++] = mush[i].w;
  }
  sort(x, x + cnt);
  int k = cnt;
  cnt = 1;
  for (int i = 1; i < k; i++)
    if (x[i] != x[cnt - 1]) x[cnt++] = x[i];
  for (int i = 0; i < n; i++) {
    if (data[i].l != 100) {
      p[find(data[i].w - data[i].h)] += log((100.0 - data[i].l) / 100);
      p[find(data[i].w)] -= log((100.0 - data[i].l) / 100);
    } else {
      num[find(data[i].w - data[i].h)]++;
      num[find(data[i].w)]--;
    }
    if (data[i].r != 100) {
      p[find(data[i].w + 1)] += log((100.0 - data[i].r) / 100);
      p[find(data[i].w + data[i].h + 1)] -= log((100.0 - data[i].r) / 100);
    } else {
      num[find(data[i].w + 1)]++;
      num[find(data[i].w + data[i].h + 1)]--;
    }
  }
  for (int i = 1; i < cnt; i++) p[i] += p[i - 1];
  for (int i = 1; i < cnt; i++) num[i] += num[i - 1];
  double ans = 0;
  for (int i = 0; i < m; i++) {
    if (num[find(mush[i].w)] == 0) ans += exp(p[find(mush[i].w)]) * mush[i].z;
  }
  printf("%.7f\n", ans);
  return 0;
}
