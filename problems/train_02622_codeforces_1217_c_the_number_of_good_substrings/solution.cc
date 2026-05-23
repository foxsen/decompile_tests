#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
const int inf = 0x3f3f3f3f;
char s[maxn];
int main() {
  int t;
  scanf("%d", &t);
  getchar();
  while (t--) {
    scanf("%s", s + 1);
    long long ans = 0, last = 0, len = strlen(s + 1);
    for (int i = 1; i <= len; i++) {
      if (s[i] == '1') {
        long long k = 0, l = 0;
        for (int j = i; j <= len && j < i + 20; j++) {
          k = k * 2 + s[j] - '0';
          l = j - k + 1;
          if (l <= last) break;
          ans++;
        }
        last = i;
      }
    }
    printf("%lld\n", ans);
  }
}
