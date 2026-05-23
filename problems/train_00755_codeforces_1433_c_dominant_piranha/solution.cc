#include <bits/stdc++.h>
using namespace std;
const int mod = 1e8 + 7;
const int N = 3e5 + 10;
int vis[N];
int main() {
  int num;
  scanf("%d", &num);
  int n, m;
  while (num--) {
    scanf("%d", &n);
    int maxx = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &vis[i]);
      maxx = max(vis[i], maxx);
    }
    int num = -1;
    for (int i = 0; i < n; i++) {
      if (vis[i] == maxx) {
        if (i - 1 >= 0 && vis[i - 1] < maxx) {
          num = i + 1;
          break;
        }
        if (i + 1 < n && vis[i + 1] < maxx) {
          num = i + 1;
          break;
        }
      }
    }
    printf("%d\n", num);
  }
  return 0;
}
