#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using namespace std;
char a[maxn];
int n, k, L[2][2];
int main() {
  scanf("%d%d", &n, &k);
  getchar();
  for (int i = 1; i <= n; i++) {
    scanf("%c", &a[i]);
    int k = a[i] - '0';
    if (L[k][0] == 0) {
      L[k][0] = i;
    }
    L[k][1] = i;
  }
  int len0 = L[0][1] - L[0][0];
  int len1 = L[1][1] - L[1][0];
  if (k > len0 || k > len1) {
    printf("tokitsukaze\n");
  } else {
    if (L[0][1] - L[0][0] == k && L[1][1] - L[1][0] == k && L[1][1] > L[0][0] &&
        L[0][1] > L[1][0]) {
      printf("quailty\n");
    } else {
      printf("once again\n");
    }
  }
  return 0;
}
