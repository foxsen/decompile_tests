#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N],b[N],n,m;
int main() {
  int x,y;
  scanf("%d%d",&n,&m);
  for (int i = 1 ; i <= m ; ++ i) {
    scanf("%d%d",&x,&y);
    if (x > y) swap(x,y);
    if (y == n) b[x] = 1;
    if (x == 1) a[y] = 1;
  }
  for (int i = 1 ; i <= n ; ++ i)
    if (a[i] && b[i]) return 0 * printf("POSSIBLE\n");
  puts("IMPOSSIBLE");
  return 0;
}