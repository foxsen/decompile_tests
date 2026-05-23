#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  int g1 = 0, g2 = 0;
  int a[n / 2];
  for (int i = 0; i < n / 2; i++) {
    cin >> a[i];
  }
  sort(a, a + n / 2);
  for (int i = 1; i <= n / 2; i++) {
    g1 += abs(a[i - 1] - (i * 2 - 1));
  }
  for (int i = 1; i <= n / 2; i++) {
    g2 += abs(a[i - 1] - (i * 2));
  }
  cout << min(g1, g2) << endl;
  return 0;
}
