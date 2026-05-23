#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const long long maxcost = 10e10;
struct node {
  int s, e, c;
} aa[maxn], bb[maxn];
int n, x;
long long minn(long long a, long long b) { return a > b ? b : a; }
long long costmin[maxn];
long long mincost;
bool cmp1(node a, node b) { return a.s < b.s; }
bool cmp2(node a, node b) { return a.e < b.e; }
void init() {
  for (int i = 0; i < maxn; i++) costmin[i] = maxcost;
}
int main() {
  while (~scanf("%d %d", &n, &x)) {
    init();
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", &aa[i].s, &aa[i].e, &aa[i].c);
      bb[i] = aa[i];
    }
    sort(aa, aa + n, cmp1);
    sort(bb, bb + n, cmp2);
    long long mincost = maxcost;
    int j = 0;
    for (int i = 0; i < n; i++) {
      while (j < n && bb[j].e < aa[i].s) {
        costmin[bb[j].e - bb[j].s + 1] =
            minn(costmin[bb[j].e - bb[j].s + 1], bb[j].c);
        j++;
      }
      int tmp = x - (aa[i].e - aa[i].s + 1);
      if (tmp > 0 && mincost > (costmin[tmp] + aa[i].c))
        mincost = (costmin[tmp] + aa[i].c);
    }
    if (mincost == maxcost)
      cout << "-1" << endl;
    else
      cout << mincost << endl;
  }
  return 0;
}
