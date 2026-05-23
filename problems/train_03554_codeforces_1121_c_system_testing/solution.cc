#include <bits/stdc++.h>
using namespace std;
int arr[1010];
bool interest[1010];
int main() {
  int n, i, j, k, x, y, ans, curr, temp, m, rose = 0;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
  }
  double systest = 0.00;
  int cek = round(systest);
  pair<int, int> p[m + 5];
  for (i = 1; i <= m; i++) {
    p[i] = make_pair(i, 0);
  }
  int next = m + 1;
  int done = 0;
  while (1) {
    temp = 0;
    for (i = 1; i <= m; i++) {
      if (p[i].first > n) {
        temp++;
        continue;
      }
      if (p[i].second == arr[p[i].first]) {
        p[i].first = next;
        p[i].second = 0;
        done++;
        systest = (100 * (double)done / (double)n);
        cek = round(systest);
        next++;
      }
      p[i].second++;
    }
    for (i = 1; i <= m; i++) {
      if (p[i].first > n) continue;
      if (p[i].second == cek) interest[p[i].first] = 1;
    }
    if (temp == m) break;
  }
  for (i = 1; i <= n; i++) {
    rose += (interest[i] == 1);
  }
  printf("%d\n", rose);
  return 0;
}
