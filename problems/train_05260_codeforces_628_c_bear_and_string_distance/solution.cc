#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 9;
char s[MAXN];
char s2[MAXN];
int main() {
  int n, k;
  cin >> n >> k;
  scanf("%s", s);
  for (int i = 0; i < (n); ++i) {
    if (s[i] - 'a' >= 'z' - s[i]) {
      if (s[i] - 'a' >= k) {
        s2[i] = s[i] - k;
        k = 0;
      } else {
        s2[i] = 'a';
        k -= s[i] - 'a';
      }
    } else {
      if ('z' - s[i] >= k) {
        s2[i] = s[i] + k;
        k = 0;
      } else {
        s2[i] = 'z';
        k -= 'z' - s[i];
      }
    }
  }
  if (k != 0)
    puts("-1");
  else
    printf("%s\n", s2);
  return 0;
}
