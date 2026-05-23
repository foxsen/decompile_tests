#include <bits/stdc++.h>
using namespace std;
int prime(long long int n) {
  for (long long int i = 2; i < n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
int sgn(long long int n) {
  if (n > 0) {
    return 1;
  } else {
    return -1;
  }
}
long long int max_digit(long long int n) {
  long long int lar = 0;
  while (n) {
    long long int r = n % 10;
    lar = max(r, lar);
    n = n / 10;
  }
  return lar;
}
long long int min_digit(long long int n) {
  long long int lar = 9;
  while (n) {
    long long int r = n % 10;
    lar = min(r, lar);
    n = n / 10;
  }
  return lar;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    long long int x = 0, y = 0;
    for (long long int i = b.size() - 1; i >= 0; i--) {
      if (b[i] == '1') {
        y = b.size() - 1 - i;
        break;
      }
    }
    long long int flag = 0;
    for (long long int i = a.size() - 1; i >= 0; i--) {
      if (a[i] == '1') {
        x = a.size() - 1 - i;
        if (x >= y) {
          cout << x - y << endl;
          flag = 1;
          break;
        }
      }
    }
    if (flag == 0) {
      cout << 0 << endl;
    }
  }
}
