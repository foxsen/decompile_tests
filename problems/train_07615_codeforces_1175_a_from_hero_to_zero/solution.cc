#include <bits/stdc++.h>
using namespace std;
int64_t R = 1;
void solution() {
  int64_t n, k, s = 0, ans = 0;
  cin >> n >> k;
  while (n > 0) {
    if (n % k == 0) {
      n = n / k;
      ans++;
    } else {
      s = n % k;
      ans += s;
      n = n - s;
    }
  }
  cout << ans << "\n";
}
int main() {
  cin >> R;
  for (long long int i = 0; i < R; i++) {
    solution();
  }
  return 0;
}
