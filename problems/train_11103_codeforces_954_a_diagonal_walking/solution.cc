#include <bits/stdc++.h>
using namespace std;
int n;
char s[200];
int ucnt, rcnt;
int main() {
  scanf("%d", &n);
  getchar();
  gets(s);
  int ans = strlen(s);
  for (int i = 0; i < n - 1; i++) {
    if ((s[i] == 'U' && s[i + 1] == 'R') || (s[i] == 'R' && s[i + 1] == 'U'))
      i++, ans--;
  }
  cout << ans << endl;
}
