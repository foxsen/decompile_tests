#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[101], n, imin = 0, imax = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (arr[i] == 1)
      imin = i;
    else if (arr[i] == n)
      imax = i;
  }
  int a;
  if (imax < imin) swap(imax, imin);
  int rsp = abs(imin - imax) + max(n - imax, imin - 1);
  cout << rsp;
  return 0;
}
