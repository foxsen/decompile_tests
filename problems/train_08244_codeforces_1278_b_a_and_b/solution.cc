#include <bits/stdc++.h>
using namespace std;
const int N = (1e6 + 12);
const int mod = (1e9 + 7);
const int INF = (0x3f3f3f3f);
int rem;
bool check(int x) {
  x = x * (x + 1) / 2;
  return x >= rem;
}
void solve() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (a > b) {
    swap(a, b);
  }
  rem = b - a;
  int sum = 0, ans = 0;
  for (int i = 0; i <= 100000; i++) {
    sum += i;
    int x = sum - rem;
    if (x % 2 == 0) {
      int y = x / 2 + rem;
      if (y <= sum && y == sum - y + rem) {
        ans = i;
        break;
      }
    }
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
