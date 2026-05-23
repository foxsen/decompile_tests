#include <bits/stdc++.h>
using namespace std;
long long int index_sum[5001];
long long int n, varr[5001];
long long int summ(int i) {
  if (i < 0) return 0;
  return index_sum[i];
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> varr[i];
    index_sum[i] = varr[i] + summ(i - 1);
  }
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (summ(j) - summ(i - 1) > 100 * (j + 1 - i)) {
        if (ans <= j + 1 - i) ans = j + 1 - i;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
