#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t;
  scanf("%d %d", &n, &k);
  t = n;
  vector<int> fact;
  for (int i = 2; i <= n; i++) {
    while (n % i == 0) {
      fact.push_back(i);
      n /= i;
    }
  }
  if (t == 1 && k == 1) {
    printf("1");
  } else if (t == 1) {
    printf("-1");
  }
  if (fact.size() < k) {
    printf("-1");
  } else {
    for (int i = 0; i < k - 1; i++) {
      printf("%d ", fact[i]);
      t /= fact[i];
    }
    printf("%d", t);
  }
  return 0;
}
