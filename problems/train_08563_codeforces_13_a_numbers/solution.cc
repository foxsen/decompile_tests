#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int num, fz = 0, fm;
  cin >> num;
  for (int i = 2; i <= num - 1; i++) {
    int tmp = num;
    while (tmp) {
      fz += tmp % i;
      tmp /= i;
    }
  }
  fm = num - 2;
  int g = gcd(fz, fm);
  cout << fz / g << "/" << fm / g << endl;
  return 0;
}
