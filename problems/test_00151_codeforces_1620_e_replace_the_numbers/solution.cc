#include <bits/stdc++.h>
using namespace std;
long long bigmod(long long base, long long power, long long modd) {
  if (power == 0)
    return 1;
  else if (power % 2 == 0) {
    long long ret = bigmod(base, power / 2, modd);
    return ((ret % modd) * (ret % modd)) % modd;
  } else {
    return ((base % modd) * (bigmod(base, power - 1, modd))) % modd;
  }
}
long long fpow(long long base, long long power) {
  long long ret = 1;
  while (power) {
    if (power % 2 == 0) {
      base = base * base;
      power /= 2;
    } else {
      ret *= base;
      power--;
    }
  }
  return ret;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long a, b, c, d, i, j, cnt = 0, lng, o = 0;
  string st;
  vector<long long> v, u, v2, u2;
  map<long long, long long> mp;
  cin >> lng;
  for (i = 0; i <= 500000; i++) mp[i] = i;
  bool bl[lng];
  for (i = 0; i < lng; i++) {
    bl[i] = 0;
    cin >> a;
    if (a == 1) {
      cin >> b;
      v.push_back(b);
      u.push_back(-1);
    } else {
      cin >> b >> c;
      v.push_back(b);
      u.push_back(c);
      bl[i] = 1;
    }
  }
  for (i = lng - 1; i >= 0; i--) {
    if (bl[i] == 0) {
      v2.push_back(mp[v[i]]);
    } else {
      mp[v[i]] = mp[u[i]];
    }
  }
  for (i = v2.size() - 1; i >= 0; i--) cout << v2[i] << " ";
  cout << endl;
  return 0;
}
