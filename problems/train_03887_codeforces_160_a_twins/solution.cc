#include <bits/stdc++.h>
using namespace std;
bool myfunction(int i, int j) { return (i > j); }
int main() {
  int n;
  int a[101];
  int sum1 = 0, sum2 = 0;
  int answer;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum2 += a[i];
  }
  sort(a, a + n, myfunction);
  for (int i = 0; i < n; i++) {
    sum1 += a[i];
    sum2 -= a[i];
    if (sum1 > sum2) {
      answer = i + 1;
      break;
    }
  }
  printf("%d\n", answer);
  return 0;
}
