#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int f[21];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int x = 0; x <= 20; x++) {
      if ((a[i] >> x) & 1) {
        f[x]++;
      }
    }
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    long long x = 0;
    for (int j = 0; j <= 20; j++) {
      if (f[j]) {
        f[j]--;
        x += 1ll * (1 << j);
      }
    }
    sum += x * x;
  }
  cout << sum << '\n';
}
