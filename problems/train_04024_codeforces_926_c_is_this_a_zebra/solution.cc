#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int result = 1;
  int currentColor = 0;
  int requiredLength = 0;
  int currentLength = 0;
  int i = 0;
  for (; i < n; ++i) {
    int cur;
    scanf("%d", &cur);
    if (cur == currentColor) {
      ++currentLength;
    } else {
      if (requiredLength == 0) {
        requiredLength = currentLength;
      } else if (currentLength != requiredLength) {
        result = 0;
        break;
      }
      currentColor = cur;
      currentLength = 1;
    }
  }
  if (requiredLength && currentLength != requiredLength) {
    result = 0;
  }
  printf((result ? "YES\n" : "NO\n"));
  return 0;
}
