#include <bits/stdc++.h>
using namespace std;
int a[120];
int n, m, k;
void swap(int x) {
  for (int i = x; i > 0; i--) {
    a[i] = a[i] + a[i - 1];
    a[i - 1] = a[i] - a[i - 1];
    a[i] = a[i] - a[i - 1];
  }
}
int pos(int x) {
  for (int i = 0; i < k; i++) {
    if (a[i] == x) return i + 1;
  }
}
int main() {
s:
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  int t = n * m, x;
  while (t--) {
    cin >> x;
    cnt += pos(x);
    swap(pos(x) - 1);
  }
  cout << cnt << endl;
  return 0;
}
