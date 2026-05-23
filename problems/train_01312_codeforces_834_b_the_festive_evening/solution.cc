#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long a, b, c, d, e, f, i, j, k, n;
  string x, y, z;
  cin >> n >> k;
  cin >> x;
  a = x.length();
  vector<long long> v(30, 0), u(30, 0);
  for (i = 0; i < a; i++) {
    b = (long long)(x[i] - 'A');
    if (v[b] == 0) v[b] = i + 1;
    u[b] = i + 1;
  }
  vector<long long> p(a + 5, 0), q(a + 5, 0);
  for (i = 0; i < 26; i++) {
    p[v[i]]++;
    q[u[i]]++;
  }
  d = 0;
  for (i = 1; i <= a; i++) {
    d += p[i];
    if (d > k) {
      cout << "YES";
      return 0;
    }
    d -= q[i];
  }
  cout << "NO";
  return 0;
}
