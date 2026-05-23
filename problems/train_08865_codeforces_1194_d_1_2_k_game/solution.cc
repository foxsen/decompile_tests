#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k % 3)
      printf("%s\n", n % 3 ? "Alice" : "Bob");
    else {
      int r = n % (k + 1);
      if (r < k && r % 3 == 0)
        printf("Bob\n");
      else
        printf("Alice\n");
    }
  }
  return 0;
}
