#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N], lim[N], sum[N], ans;
void count(int l, int r) {
  for (int i = (int)(1); i <= (int)(n); i++) lim[i] = sum[i];
  int len = r - l + 1;
  for (int i = (int)(1); i <= (int)(len / 2); i++)
    if ((lim[a[r - i + 1]] -= 2) < 0)
      return;
    else
      ++ans;
  if (len & 1)
    if (--lim[a[r - len / 2]] < 0)
      return;
    else
      ++ans;
  for (int i = (int)(len / 2); i >= (int)(1); i--)
    if (a[l + i - 1] != a[r - i + 1])
      return;
    else
      ++ans;
}
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  int l = 1, r = n, cnt = 0;
  for (; l <= r && a[l] == a[r]; ++l, --r)
    ;
  if (l > r) return printf("%lld\n", 1ll * n * (n + 1) / 2), 0;
  for (int i = (int)(l); i <= (int)(r); i++) sum[a[i]]++;
  for (int i = (int)(1); i <= (int)(n); i++) cnt += (sum[i] & 1);
  if (cnt >= 2) return puts("0"), 0;
  count(l, r);
  reverse(a + l, a + r + 1);
  count(l, r);
  printf("%lld\n", 1ll * ans * l + 1ll * l * l);
}
