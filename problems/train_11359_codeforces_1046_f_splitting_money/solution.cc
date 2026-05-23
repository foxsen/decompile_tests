#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, i, j, k, l, m, n;
  cin >> n;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  long long x, f;
  cin >> x >> f;
  sort(a, a + n, greater<int>());
  long long s = 0;
  for (i = 0; i < n; i++) {
    if (a[i] > x) {
      long long d = a[i] - x;
      long long second = x + f;
      long long a = d / second;
      if (d % second != 0) a += 1;
      s += f * a;
    }
  }
  cout << s << endl;
}
