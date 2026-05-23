#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long counter = n;
  while (n > 1) {
    bool flag = false;
    for (long long i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        n = n / (int)i;
        counter += n;
        flag = true;
        break;
      }
    }
    if (!flag) {
      n = 1;
      counter += 1;
    }
  }
  cout << counter;
}
