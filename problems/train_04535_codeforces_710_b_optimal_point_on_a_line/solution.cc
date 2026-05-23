#include <bits/stdc++.h>
using namespace std;
const int OO = 1e5 + 10;
const long long MOD = 1e9 + 7;
const int MAX = 1e6;
const double EPS = (1e-9);
int arr[312345];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  sort(arr + 1, arr + n + 1);
  for (int i = 1; i <= n; i++) {
    int x = arr[i];
    if (n % 2 && i == n / 2 + 1) {
      cout << x << '\n';
      return 0;
    }
    if (n % 2 == 0 && i == n / 2) {
      cout << x << '\n';
    }
  }
  return 0;
}
