#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, arr[100], sumprofit = 0, profit = 0, m, noplace = 0, multi = 0;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  cin >> m;
  if (m <= n) {
    for (int i = 0; i < m; i++) {
      profit += arr[i];
    }
  } else {
    for (int i = 0; i < n; i++) {
      profit += arr[i];
    }
    profit -= d * (m - n);
  }
  cout << profit << endl;
  return 0;
}
