#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;
const int M = 1e6 + 11;
int degree[M];
int arr[M];
int ans[N];
int vis[M];
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    memset(degree, 0, sizeof(degree));
    memset(vis, 0, sizeof(vis));
    int a, b;
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &a, &b);
      ++degree[b];
      arr[a] = b;
      vis[a] = vis[b] = true;
    }
    int tmp = 0;
    for (int i = 2; i <= n; i += 2) {
      ans[i] = arr[tmp];
      tmp = ans[i];
    }
    for (int i = 1; i < M; ++i) {
      if (vis[i] && degree[i] == 0) {
        tmp = i;
        break;
      }
    }
    for (int i = 1; i <= n; i += 2) {
      ans[i] = tmp;
      tmp = arr[tmp];
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d", ans[i]);
      if (i == n)
        printf("\n");
      else
        printf(" ");
    }
  }
}
