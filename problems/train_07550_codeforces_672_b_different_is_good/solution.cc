#include <bits/stdc++.h>
using namespace std;
const int maxn = 26 + 5;
int n;
string s;
bool cnt[maxn];
int main() {
  while (cin >> n) {
    cin >> s;
    if (s.length() > 26) {
      printf("-1\n");
      continue;
    }
    memset(cnt, 0, sizeof(cnt));
    int tot = 0;
    for (int i = 0; i < s.length(); i++)
      if (!cnt[s[i] - 'a']) {
        cnt[s[i] - 'a'] = 1;
        tot++;
      }
    printf("%d\n", (int)s.length() - tot);
  }
  return 0;
}
