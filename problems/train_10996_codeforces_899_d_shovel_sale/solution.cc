#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  long long int n;
  cin >> n;
  if (n <= 4) {
    cout << ((n - 1) * n) / 2 << endl;
    return 0;
  }
  long long int val = n + n - 1, cnt = 0, num = 0, adder = 1;
  while (val) {
    val /= 10;
    cnt++;
  }
  if (n + n - 1 != 9 and n + n - 1 != 99 and n + n - 1 != 999 and
      n + n - 1 != 9999 and n + n - 1 != 99999 and n + n - 1 != 999999 and
      n + n - 1 != 9999999 and n + n - 1 != 99999999 and
      n + n - 1 != 999999999ll and n + n - 1 != 9999999999ll)
    cnt--;
  long long int aux = cnt, ans = 0;
  while (aux--) {
    num = num * 10 + 9;
    adder *= 10;
  }
  val = n + n - 1;
  while (num <= val) {
    ans += max(0ll, min(n, num - 1) - num / 2);
    num += adder;
  }
  cout << ans << endl;
  return 0;
}
