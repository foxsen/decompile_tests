#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie(0);
  int n;
  long long m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    a[i] = a[i - 1] + x;
  }
  long long tmp = 0;
  for (int i = 1; i <= n; i++) {
    cout << a[i] / m - tmp << " ";
    tmp += (a[i] / m - tmp);
  }
}
