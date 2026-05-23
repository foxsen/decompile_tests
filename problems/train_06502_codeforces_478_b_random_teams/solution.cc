#include <bits/stdc++.h>
using namespace std;
int main() {
  long m, n;
  cin >> n >> m;
  long long kmax = 1ll * (n - m) * (n - m + 1) / 2ll;
  long long kmin = (1ll * (n % m) * (n / m + 1) * (n / m) +
                    1ll * (m - n % m) * (n / m) * (n / m - 1)) /
                   2ll;
  cout << kmin << " " << kmax << endl;
}
