#include <bits/stdc++.h>
using namespace std;
int arr[505000], ans;
void updata(int l, int r) {
  int i = l + 1, j = r - 1;
  while (i <= j) {
    arr[i] = arr[l];
    arr[j] = arr[r];
    i++, j--;
  }
  ans = max(ans, (r - l) / 2);
}
int main() {
  int n;
  scanf("%d", &n);
  ans = 0;
  int st = 0, ed = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if (i) {
      if (arr[i] != arr[i - 1])
        ed++;
      else {
        updata(st, ed);
        st = i;
        ed = i;
      }
    }
  }
  updata(st, ed);
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", arr[i]);
  }
  printf("\n");
  return 0;
}
