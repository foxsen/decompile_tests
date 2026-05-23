#include <bits/stdc++.h>
int n, a, b, m, f, male[400], female[400], ans;
char gender;
int main() {
  scanf(" %d", &n);
  for (int i = 0; i < n; i++) {
    scanf(" %c %d %d", &gender, &a, &b);
    if (gender == 'M') {
      male[a]++;
      male[b + 1]--;
    } else {
      female[a]++;
      female[b + 1]--;
    }
  }
  for (int i = 1; i <= 366; i++) {
    m += male[i];
    f += female[i];
    ans = std::max(ans, std::min(m, f) * 2);
  }
  printf("%d", ans);
  return 0;
}
