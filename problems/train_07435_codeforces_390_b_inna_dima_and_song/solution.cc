#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5 + 10;
int a[SIZE], b[SIZE];
int main() {
  int(n);
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) scanf("%d", &(a[i]));
  for (int i = 0; i < (n); ++i) scanf("%d", &(b[i]));
  long long an = 0;
  for (int i = 0; i < (n); ++i) {
    if (b[i] != 1 && a[i] * 2 >= b[i])
      an += (long long)b[i] / 2 * (b[i] - b[i] / 2);
    else
      an--;
  }
  cout << an << endl;
  return 0;
}
