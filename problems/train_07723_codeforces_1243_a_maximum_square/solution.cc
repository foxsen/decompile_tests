#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int arr[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    sort(arr + 1, arr + 1 + n);
    int ans = 0;
    for (int i = n; i > 0; i--) ans = max(ans, min(arr[i], n - i + 1));
    printf("%d\n", ans);
  }
  return 0;
}
