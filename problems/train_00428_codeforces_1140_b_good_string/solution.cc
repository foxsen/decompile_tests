#include <bits/stdc++.h>
using namespace std;
void pikachu() {}
short t, n;
char a[111];
int main() {
  pikachu();
  scanf("%hd", &t);
  short u, v;
  while (t--) {
    scanf("%hd", &n);
    scanf("%s", a + 1);
    u = 0;
    v = n + 1;
    for (short i = 1; i <= n; ++i) {
      if (a[i] == '<')
        u = i;
      else
        v = min(v, i);
    }
    printf("%hd\n", min(v - 1, n - u));
  }
}
