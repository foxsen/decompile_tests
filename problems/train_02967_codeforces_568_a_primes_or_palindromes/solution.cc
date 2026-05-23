#include <bits/stdc++.h>
using namespace std;
int p, q;
int rev(int x) {
  int ret = 0;
  while (x) {
    ret *= 10;
    ret += x % 10;
    x /= 10;
  }
  return ret;
}
bool vis[4000000 + 10];
void init() {
  vis[1] = 1;
  for (int i = 2; i <= 4000000; i++)
    if (!vis[i])
      for (int j = i + i; j <= 4000000; j += i) vis[j] = 1;
}
int main() {
  int ans = -1;
  int A = 0, B = 0;
  scanf("%d%d", &p, &q);
  init();
  for (int i = 1; i <= 4000000; i++) {
    if (i == rev(i)) B++;
    if (!vis[i]) A++;
    if (q * (long long)A <= p * (long long)B) ans = i;
  }
  if (ans == -1)
    puts("Palindromic tree is better than splay tree");
  else
    printf("%d", ans);
}
