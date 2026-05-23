#include <bits/stdc++.h>
using namespace std;
void autoinput() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
const long long mod = 1000000007;
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long bigmod(long long N, long long P) {
  if (P == 0) return 1;
  if (P % 2 == 0) {
    long long ret = bigmod(N, P / 2);
    return ((ret % mod) * (ret % mod)) % mod;
  } else
    return ((N % mod) * (bigmod(N, P - 1) % mod)) % mod;
}
long long modInverse(long long a, long long m) { return bigmod(a, m - 2); }
vector<long long> prime_fact[100005], primes;
bool prime[100005];
map<long long, long long> visited, taken;
void sieve() {
  long long i, n = 1e5;
  n++;
  for (i = 2; i < n; i++) {
    if (!prime[i]) {
      primes.push_back(i);
      for (long long j = i; j < n; j += i) {
        prime_fact[j].push_back(i);
        prime[j] = 1;
      }
    }
  }
}
int main() {
  long long t, T;
  sieve();
  long long i, j, k, l, m, n;
  scanf("%lld", &n);
  scanf("%lld", &m);
  for (i = 0; i < m; i++) {
    char c;
    scanf("%c", &c);
    if (c == '\n') scanf("%c", &c);
    scanf("%lld", &k);
    if (c == '+') {
      if (visited[k]) {
        printf("Already on\n");
        continue;
      } else {
        long long fl = 1;
        long long x;
        for (auto it : prime_fact[k]) {
          if (taken[it] != 0) {
            x = taken[it];
            fl = 0;
            break;
          }
        }
        if (!fl) {
          printf("Conflict with %lld\n", x);
        } else {
          visited[k] = 1;
          for (auto it : prime_fact[k]) {
            taken[it] = k;
          }
          printf("Success\n");
        }
      }
    } else {
      if (!visited[k]) {
        printf("Already off\n");
      } else {
        visited[k] = 0;
        for (auto it : prime_fact[k]) {
          taken[it] = 0;
        }
        printf("Success\n");
      }
    }
  }
}
