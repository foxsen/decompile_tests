#include <bits/stdc++.h>
using namespace std;
const long long DIVN = 1000000007;
int main(int argc, char const *argv[]) {
  int n, m, k, calc;
  long long res = 1;
  cin >> n >> m >> k;
  if (k == 1 || k > n)
    calc = n;
  else if (k < n && (!(k % 2)))
    calc = 1;
  else if (k < n && (k % 2))
    calc = 2;
  else if (k == n)
    calc = n / 2 + n % 2;
  for (int i = 0; i < calc; i++) res = (res * m) % DIVN;
  cout << res << endl;
  return 0;
}
