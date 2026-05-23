#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
int main() {
  long long a;
  cin >> a;
  long long p10 = 1;
  for (int i = 1; i <= 18; ++i) p10 = p10 * 10;
  long long x = 9 * ((9 * p10) % a) % a;
  cout << a - x << " " << a - x + p10 - 1 << endl;
  return 0;
}
