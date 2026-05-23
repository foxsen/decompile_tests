#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a - (a / b * b));
}
long long mypow(long long a, long long b) {
  long long p = 1;
  if (b == 0) return 1;
  for (long long i = 0; i < b; i++) p *= a;
  return p;
}
long long zero(long long a) {
  long long za = 0;
  long long temp = a;
  long long tens = 0;
  while (temp > 0) {
    if (temp % 10 != 0) {
      za += ((temp % 10) * (mypow(10, tens)));
      tens++;
    }
    temp /= 10;
  }
  return za;
}
int main() {
  int x, y;
  while (cin >> x >> y) {
    bool rt = 1, up = 0, lt = 0, dn = 0;
    int i = 0, j = 0;
    int d = 1;
    int cnt = 0;
    int trn = 0;
    while (i != x || j != y) {
      if (rt) {
        i++;
        cnt++;
        if (cnt == d) {
          rt = false;
          up = true;
          cnt = 0;
          trn++;
          if (i == x && j == y) {
            cout << trn - 1 << endl;
            return 0;
          }
        }
      } else if (up) {
        j++;
        cnt++;
        if (cnt == d) {
          up = false;
          lt = true;
          cnt = 0;
          d++;
          trn++;
          if (i == x && j == y) {
            cout << trn - 1 << endl;
            return 0;
          }
        }
      } else if (lt) {
        i--;
        cnt++;
        if (cnt == d) {
          lt = false;
          dn = true;
          cnt = 0;
          trn++;
          if (i == x && j == y) {
            cout << trn - 1 << endl;
            return 0;
          }
        }
      } else if (dn) {
        j--;
        cnt++;
        if (cnt == d) {
          dn = false;
          rt = true;
          cnt = 0;
          d++;
          trn++;
          if (i == x && j == y) {
            cout << trn - 1 << endl;
            return 0;
          }
        }
      }
    }
    cout << trn << endl;
  }
  return 0;
}
