#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  pair<int, int> p[1005];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &p[i].first, &p[i].second);
    int ans = 0;
    while (1) {
      int we = p[i].second / p[i].first;
      p[i].second -= p[i].first * we;
      ans += we;
      if (p[i].second < p[i].first) {
        swap(p[i].first, p[i].second);
      }
      if (p[i].first == 0) {
        break;
      }
    }
    printf("%d\n", ans);
  }
}
