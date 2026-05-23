#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int n = (y - x) * t1;
  if (n < 0) n = -n;
  int m = (y - x) * t2;
  if (m < 0) m = -m;
  m = m + 3 * t3;
  int l = (z - x) * t2;
  if (l < 0) l = -l;
  m = m + l;
  if (m > n)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
