#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
char s[maxn];
inline int id(char ch) { return ch - 'a'; }
inline int calc(char a, char b) {
  return min((id(a) - id(b) + 26) % 26, (id(b) - id(a) + 26) % 26);
}
int main() {
  int n, p;
  scanf("%d%d%s", &n, &p, s + 1);
  int l = p, r = p;
  if (p <= n / 2) {
    for (int i = 1; i <= n / 2; i++) {
      if (s[i] != s[n - i + 1]) {
        l = min(l, i);
        r = max(r, i);
      }
    }
  } else {
    for (int i = n / 2 + 1; i <= n; i++) {
      if (s[i] != s[n - i + 1]) {
        l = min(l, i);
        r = max(r, i);
      }
    }
  }
  int res[2] = {0, 0};
  for (int i = p; i >= l; i--) res[0] += calc(s[i], s[n - i + 1]);
  if (r > p) {
    res[0] += 2 * (p - l);
    for (int i = p + 1; i <= r; i++) res[0] += calc(s[i], s[n - i + 1]);
    res[0] += r - p;
  } else
    res[0] += p - l;
  for (int i = p; i <= r; i++) res[1] += calc(s[i], s[n - i + 1]);
  if (l < p) {
    res[1] += 2 * (r - p);
    for (int i = p - 1; i >= l; i--) res[1] += calc(s[i], s[n - i + 1]);
    res[1] += p - l;
  } else
    res[1] += r - p;
  printf("%d\n", min(res[0], res[1]));
  return 0;
}
