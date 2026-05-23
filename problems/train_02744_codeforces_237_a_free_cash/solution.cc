#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int h[n], m[n];
  for (int(i) = (0); (i) < (n); (i)++) cin >> h[i] >> m[i];
  int maxi = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    int a = 1;
    while (i + a < n && h[i] == h[i + a] && m[i] == m[i + a]) a++;
    i += (a - 1);
    maxi = max(maxi, a);
  }
  cout << maxi << endl;
}
