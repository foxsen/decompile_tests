#include <bits/stdc++.h>
using namespace std;
priority_queue<long long int, vector<long long int>, greater<long long int> > t;
vector<long long int> p[200005], s(5000005, 0), d(5000005, 0);
map<pair<long long int, long long int>, long long int> mp;
set<pair<long long int, long long int> > q;
long long int mxn = 200005;
long long int n, m, k;
map<long long int, long long int> v;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int bpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res % 1000000007;
}
long long int fact(long long int n) {
  if (n == 0) return 1;
  return n * fact(n - 1);
}
long long int isprime(long long int n) {
  for (long long int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return 0;
  return 1;
}
void prime() {
  for (long long int i = 2; i <= 5000000; i++) {
    if (s[i] == 0) {
      for (long long int j = 2; i * j <= 5000000; j++) {
        s[i * j] = 1;
      }
    }
  }
}
bool pal(long long int i) {
  long long int j = i, c = 0, d = 0;
  while (j > 0) {
    c++;
    j /= 10;
  }
  for (long long int j = 1; j <= c / 2; j++) {
    d *= 10;
    d += i % 10;
    i /= 10;
  }
  if (c & 1) i /= 10;
  return (i == d);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, s;
  cin >> n >> s;
  long long int i = 0, j = 0, sum = 0, c = 0;
  for (i = s; i <= n; i++) {
    j = i;
    sum = 0;
    while (j > 0) {
      sum += j % 10;
      j /= 10;
    }
    if ((i - sum) >= s) break;
  }
  cout << (n - i + 1) * ((n - i + 1) > 0) << "\n";
}
