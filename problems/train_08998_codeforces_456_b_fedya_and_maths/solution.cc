#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  long long int a = str.size();
  if (a == 1) {
    long long int k = str[0] + 1 - '1';
    if (k % 2 != 0) {
      cout << 0;
      return 0;
    } else {
      long long int t = pow(2, k + 1);
      t = t + 2;
      t = t % 5;
      cout << t;
      return 0;
    }
  } else {
    long long int m = str[a - 2] + 1 - '1';
    long long int n = str[a - 1] + 1 - '1';
    if (n % 2 != 0) {
      cout << 0;
      return 0;
    }
    int sum = (10 * m) + n;
    sum = sum % 4;
    sum = sum + 1;
    long long int t = pow(2, sum);
    t = t + 2;
    t = t % 5;
    cout << t;
    ;
    return 0;
  }
}
