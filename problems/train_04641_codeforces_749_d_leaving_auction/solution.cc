#include <bits/stdc++.h>
using namespace std;
vector<int> val[200001];
int lst[200001];
int indx[200001];
int notBe[200001];
int cmp(int a, int b) { return lst[a] < lst[b]; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) val[i].push_back(0);
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    val[a].push_back(b);
    lst[a] = b;
    indx[i] = i;
  }
  sort(indx + 1, indx + n + 1, cmp);
  int q;
  scanf("%d", &q);
  while (q--) {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
      scanf("%d", &notBe[i]);
      lst[notBe[i]] = -1;
    }
    int per[3] = {0};
    int cnt = 0;
    for (int i = n; i >= 1; i--) {
      if (lst[indx[i]] == -1) continue;
      per[cnt++] = indx[i];
      if (cnt == 2) break;
    }
    if (lst[per[0]] == 0) {
      puts("0 0");
    } else {
      int l = -1;
      int r = val[per[0]].size() - 1;
      while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (val[per[0]][mid] <= lst[per[1]])
          l = mid;
        else
          r = mid;
      }
      printf("%d %d\n", per[0], val[per[0]][r]);
    }
    for (int i = 0; i < k; i++) {
      lst[notBe[i]] = val[notBe[i]].back();
    }
  }
  return 0;
}
