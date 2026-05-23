#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[100000];
int taken[256] = {-1};
int picked, cur;
signed main() {
  cin >> n >> k;
  for (int i = 0; i < 256; i++) taken[i] = -1;
  for (int i = 0; i < n; i++) {
    cin >> cur;
    picked = cur;
    for (int j = cur; j >= max(0, cur - k + 1); j--) {
      if (taken[j] == -1) {
        picked = j;
      }
      if (taken[j] != -1) {
        if (cur - taken[j] + 1 <= k) picked = taken[j];
        break;
      }
    }
    for (int j = picked; j <= cur; j++) {
      taken[j] = picked;
    }
    cout << picked << ' ';
  }
  return 0;
}
