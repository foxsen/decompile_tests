#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int n, cnt;
int head[N], nex[N << 1], to[N << 1];
int val[N];
int ans = -0x3f3f3f3f, fans;
map<int, int> siz;
void addedge(int a, int b) {
  nex[++cnt] = head[a];
  head[a] = cnt;
  to[cnt] = b;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &val[i]);
    siz[val[i]]++;
    ans = ((ans) > (val[i]) ? (ans) : (val[i]));
  }
  fans = ans + 2;
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    addedge(x, y);
    addedge(y, x);
  }
  for (int i = 1; i <= n; i++) {
    bool is = 0;
    for (int j = head[i]; j; j = nex[j]) {
      int v = to[j];
      siz[val[v]]--;
      if (val[v] == ans) is = 1;
    }
    if (!siz[ans]) {
      fans = ans + 1;
    }
    if (ans == val[i] && siz[val[i]] == 1) {
      if (siz[ans - 1])
        fans = ans + 1;
      else if (is)
        fans = ans + 1;
      else {
        fans = ans;
        printf("%d", fans);
        return 0;
      }
    }
    for (int j = head[i]; j; j = nex[j]) siz[val[to[j]]]++;
  }
  printf("%d", fans);
  return 0;
}
