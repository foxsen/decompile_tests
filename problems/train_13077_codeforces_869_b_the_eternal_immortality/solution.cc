#include <bits/stdc++.h>
using namespace std;
int main() {
  long long A, B;
  cin >> A >> B;
  long long ret = 1;
  for (long long i = A + 1; i <= B; i++) {
    ret *= i;
    ret %= 10;
    if (ret == 0) {
      cout << 0;
      return 0;
    }
  }
  cout << ret;
  return 0;
}
