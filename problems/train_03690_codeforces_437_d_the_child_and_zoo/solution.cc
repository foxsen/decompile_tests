#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100005], num[100005];
int family[100005];
double ans = 0;
struct node {
  int le, ri;
  int quan;
} edge[100005];
bool comp(node xx, node yy) { return xx.quan > yy.quan; }
int Find(int x) { return family[x] == x ? x : family[x] = Find(family[x]); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    family[i] = i;
    num[i] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &edge[i].le, &edge[i].ri);
    edge[i].quan = min(a[edge[i].le], a[edge[i].ri]);
  }
  sort(edge + 1, edge + m + 1, comp);
  for (int i = 1; i <= m; ++i) {
    int le_f = Find(edge[i].le);
    int ri_f = Find(edge[i].ri);
    if (le_f == ri_f) continue;
    ans += (double)(num[le_f]) * (double)(num[ri_f]) * (double)(edge[i].quan);
    family[le_f] = ri_f;
    num[ri_f] += num[le_f];
  }
  printf("%lf\n", ans * 2 / (double)(n) / (double)(n - 1));
  return 0;
}
