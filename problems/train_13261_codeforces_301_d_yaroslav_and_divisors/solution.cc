#include <bits/stdc++.h>
using namespace std;
const int N = 201000;
int n, a[N], pos[N], l[N], r[N], C[N], idx[N], ans[N];
vector<int> nu[N];
void bitModify(int p) {
  for (int i = p; i > 0; i -= i & -i) C[i]++;
}
int bitQuery(int p) {
  int ret = 0;
  for (int i = p; i <= n; i += i & -i) ret += C[i];
  return ret;
}
bool cmp(int a, int b) { return r[a] < r[b]; }
int main() {
  int nq;
  scanf("%d%d", &n, &nq);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; i * j <= n; j++) {
      int a = pos[i];
      int b = pos[i * j];
      if (a > b) swap(a, b);
      nu[b].push_back(a);
    }
  }
  for (int i = 0; i < nq; i++) {
    scanf("%d%d", &l[i], &r[i]);
    idx[i] = i;
  }
  sort(idx, idx + nq, cmp);
  int p = 0;
  for (int i = 0; i < nq; i++) {
    int ll = l[idx[i]];
    int rr = r[idx[i]];
    while (p < rr) {
      p++;
      for (int i = 0; i < (int)nu[p].size(); i++) {
        bitModify(nu[p][i]);
      }
    }
    ans[idx[i]] = bitQuery(ll);
  }
  for (int i = 0; i < nq; i++) {
    printf("%d%c", ans[i], " \n"[i == nq - 1]);
  }
  return 0;
}
