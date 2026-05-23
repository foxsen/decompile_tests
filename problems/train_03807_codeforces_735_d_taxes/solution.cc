#include <bits/stdc++.h>
using namespace std;
bool check_prime(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
int check_ps(long long n) {
  for (int i = n; i >= 2; i--) {
    bool d = check_prime(i);
    if (d) return i;
  }
}
int check_div(long long n) {
  int ans = 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) ans = i;
  }
  return ans;
}
int main() {
  long long n, a;
  while (cin >> n) {
    if (n == 2 || check_prime(n))
      cout << 1 << endl;
    else if (n % 2 == 0)
      cout << 2 << endl;
    else {
      int a = check_ps(n);
      a = n - a;
      bool d = check_prime(a);
      if (d)
        cout << 2 << endl;
      else {
        cout << 3 << endl;
      }
    }
  }
}
