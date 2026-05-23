#include <bits/stdc++.h>
using namespace std;
long long pow_mod(long long nn, long long pp, long long mm) {
  long long res = 1;
  while (pp > 0) {
    if (pp & 1) res = (res * nn) % mm;
    pp = pp >> 1;
    nn = (nn * nn) % mm;
  }
  return res;
}
void dhimanda();
int main() {
  0;
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  for (int(i) = (1); (i) <= (t); (i)++) {
    dhimanda();
  }
  return 0;
}
void dhimanda() {
  long long n;
  cin >> n;
  long long x = ceil(n / 4.0);
  for (int i = 1; i <= n - x; i++) cout << "9";
  for (int i = 1; i <= x; i++) cout << "8";
  cout << '\n';
}
