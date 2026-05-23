#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    if (n < l)
      cout << "No" << endl;
    else if ((n >= l && n <= r) || (n / l * r >= n) || (r >= 2 * l - 1))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
