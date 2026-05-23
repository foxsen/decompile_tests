#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, a, b, k, p;
  pair<int, int> cell[1001];
  cin >> n;
  k = 0;
  p = 0;
  for ((i) = (0); (i) < (int)(n); (i)++) {
    cin >> a >> b;
    if (a == 0) k++;
    if (b == 0) p++;
  }
  int sum;
  sum = 0;
  sum += min(k, n - k);
  sum += min(p, n - p);
  cout << sum << endl;
  return 0;
}
