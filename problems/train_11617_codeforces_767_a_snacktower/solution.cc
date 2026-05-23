#include <bits/stdc++.h>
using namespace std;
int a[100005], vis[100005];
int main() {
  int n;
  scanf("%d", &n);
  int t = n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    vis[a[i]] = 1;
    for (; vis[t] == 1; t--) printf("%d ", t);
    printf("\n");
  }
  return 0;
}
