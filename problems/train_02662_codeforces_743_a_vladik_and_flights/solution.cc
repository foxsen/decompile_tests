#include <bits/stdc++.h>
using namespace std;
int main() {
  char arr[100005];
  int n, i, a, b;
  while (scanf("%d %d %d", &n, &a, &b) == 3) {
    getchar();
    for (i = 1; i <= n; i++) scanf("%c", &arr[i]);
    if (arr[a] != arr[b])
      printf("1\n");
    else if (arr[a] == arr[b])
      printf("0\n");
  }
  return 0;
}
