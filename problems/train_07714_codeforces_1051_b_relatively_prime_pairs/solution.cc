#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r;
  cin >> l >> r;
  cout << "YES\n";
  long long i;
  for (i = l; i <= r; i += 2) cout << i << ' ' << i + 1 << endl;
}
