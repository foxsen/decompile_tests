#include <bits/stdc++.h>
using namespace std;
long long a, b;
vector<long long> vect;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(0);
  int i;
  long long ans = 0;
  cin >> a >> b;
  for (i = 1; i * 1ll * i <= a; i++)
    if (a % (i * 1ll) == 0) {
      vect.push_back(i);
      if ((i * 1ll) != a / (i * 1ll)) vect.push_back(a / (i * 1ll));
    }
  sort(vect.begin(), vect.end());
  while (b > 0) {
    long long curr = gcd(a, b);
    int pos = lower_bound(vect.begin(), vect.end(), curr) - vect.begin();
    long long p = 0;
    for (i = pos + 1; i < vect.size(); i++) {
      long long d = b / vect[i];
      if ((b - (d * vect[i])) % curr == 0) p = max(p, d * vect[i]);
    }
    ans += (b - p) / curr;
    b = p;
  }
  cout << ans;
  return 0;
}
