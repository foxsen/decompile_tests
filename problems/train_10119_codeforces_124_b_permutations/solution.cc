#include <bits/stdc++.h>
using namespace std;
char arr[10][10];
char my[10][10];
int n, k;
int ans = 1000000000;
int getLen() {
  int mi = 1000000000, ma = 0;
  for (int i = 0; i < n; i++) {
    int num = 0;
    int st = 1;
    for (int j = k - 1; j >= 0; --j) {
      num += st * arr[i][j];
      st *= 10;
    }
    if (num < mi) mi = num;
    if (num > ma) ma = num;
  }
  return (ma - mi);
}
int per[10];
void go(int idx = 0) {
  if (idx == k) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        arr[i][j] = my[i][per[j]];
      }
    }
    int le = getLen();
    if (le < ans) ans = le;
  }
  for (int i = 0; i < k; i++) {
    bool fo = 0;
    for (int j = 0; j < idx; j++) {
      if (per[j] == i) {
        fo = 1;
        break;
      }
    }
    if (!fo) {
      per[idx] = i;
      go(idx + 1);
    }
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    for (int j = 0; j < k; j++) {
      arr[i][j] -= '0';
      my[i][j] = arr[i][j];
    }
  }
  go(0);
  cout << ans << endl;
  return 0;
}
