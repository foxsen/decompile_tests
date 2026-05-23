#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    long long a = n;
    long long b = n;
    if (n >= 2) {
      a += n * (n - 1);
      b += n * (n - 1) * 2;
    }
    if (n >= 3) {
      a += n * (n - 1) * (n - 2) / 6;
      b += n * (n - 1) * (n - 2);
    }
    if (n >= 4) {
      long long tmp = n;
      tmp = tmp * (n - 1) * (n - 2) * (n - 3) / 6;
      b += tmp;
    }
    if (n >= 5) {
      long long tmp = n;
      tmp = tmp * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 6 / 4 / 5;
      b += tmp;
    }
    cout << a * b << endl;
  }
}
