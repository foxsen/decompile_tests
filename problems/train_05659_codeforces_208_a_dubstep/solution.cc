#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx")
const long long MOD = 1000000007;
const long double PI = 3.1415926535898;
const long long LIM = 100005;
using namespace std;
long long fpow(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = fpow(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void sieve(long long n) {
  bool prime[5 * LIM];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++)
    if (prime[p] == true)
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
  prime[1] = 0;
}
inline long long read() {
  long long p = 1, ans = 0;
  char ch = getchar();
  while (ch < 48 || ch > 57) {
    if (ch == '-') p = -1;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57) {
    ans = (ans << 3) + (ans << 1) + ch - 48;
    ch = getchar();
  }
  return ans * p;
}
void findAndReplaceAll(std::string& data, std::string toSearch,
                       std::string replaceStr) {
  size_t pos = data.find(toSearch);
  while (pos != std::string::npos) {
    data.replace(pos, toSearch.size(), replaceStr);
    pos = data.find(toSearch, pos + replaceStr.size());
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  findAndReplaceAll(s, "WUB", "1");
  for (long long i = 0; i < s.length();) {
    if (s[i] != '1') {
      long long pos = s.find('1', i);
      if (pos != string::npos) {
        cout << s.substr(i, pos - i) << " ";
        i = pos;
      } else {
        cout << s.substr(i);
        break;
      }
    } else
      i++;
  }
  return 0;
}
