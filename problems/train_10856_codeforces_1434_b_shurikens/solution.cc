#include <bits/stdc++.h>
using namespace std;
int n, x;
char s[100086];
int id[100086], tag[100086], cnt;
int sk[100086], top;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n; i++) {
    scanf("%s", s);
    if (s[0] == '+') {
      sk[++top] = ++cnt;
    } else {
      scanf("%d", &x);
      if (!top || tag[sk[top]] > x) return printf("NO"), 0;
      id[sk[top--]] = x;
      if (top) tag[sk[top]] = max(tag[sk[top]], x);
    }
  }
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d ", id[i]);
}
