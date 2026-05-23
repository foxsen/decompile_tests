#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > coprime(100001);
void prime_factorization() {
  for (long long i = 2; i <= 100001; i += 2) {
    coprime[i].push_back(2);
  }
  for (long long i = 3; i <= 100001; i += 3) {
    coprime[i].push_back(3);
  }
  for (long long i = 5; i <= 50000; i += 6) {
    if (coprime[i].size() == 0) {
      for (long long j = i; j <= 100000; j += i) {
        coprime[j].push_back(i);
      }
    }
    if (coprime[i + 2].size() == 0) {
      for (long long j = i + 2; j <= 100000; j += i + 2) {
        coprime[j].push_back(i + 2);
      }
    }
  }
}
bool isprime(long long n) {
  if (n < 2) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0) return false;
  if (n % 3 == 0) return false;
  for (long long i = 5; i <= sqrt(n); i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
long long bin_power(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    n >>= 1;
  }
  return res % 1000000007;
}
long long p_factors(long long &n, long long p) {
  long long res = 0;
  while (n % p == 0) {
    res++;
    n = n / p;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long extended_gcd(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  long long x1, y1;
  long long g = extended_gcd(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return g;
}
void simple_sieve(long long n, vector<long long> &primes) {
  if (n < 2) return;
  if (n < 3) {
    primes.push_back(2);
    return;
  }
  vector<bool> mark(n + 1, true);
  mark[2] = true;
  mark[3] = true;
  primes.push_back(2);
  primes.push_back(3);
  for (long long i = 5; i * i < n; i += 6) {
    if (mark[i]) {
      for (long long j = i * i; j < n; j += i) mark[j] = false;
    }
    if (mark[i + 2] && (i + 2) < sqrt(n)) {
      for (long long j = (i + 2) * (i + 2); j < n; j += (i + 2))
        mark[j] = false;
    }
  }
  for (long long i = 5; i < n; i += 6) {
    if (mark[i]) primes.push_back(i);
    if (mark[i + 2] && (i + 2) < n) primes.push_back(i + 2);
  }
}
void linear_sieve(long long n, vector<long long> &primes) {
  if (n < 2) return;
  if (n < 3) {
    primes.push_back(2);
    return;
  }
  vector<long long> mark(n + 1);
  for (long long i = 2; i <= n; i++) {
    if (mark[i] == 0) {
      primes.push_back(i);
      mark[i] = i;
    }
    for (long long j = 0;
         j < primes.size() && primes[j] <= mark[i] && i * primes[j] <= n; j++)
      mark[i * primes[j]] = primes[j];
  }
}
void segmented_sieve(long long n, vector<long long> &primes) {
  if (n < 2) return;
  long long limit = sqrt(n) + 1;
  simple_sieve(limit, primes);
  long long low = limit;
  long long high = 2 * limit;
  while (low < n) {
    if (high >= n) high = n + 1;
    vector<bool> mark(high - low + 2, true);
    for (long long i = 0; i < primes.size(); i++) {
      long long lolim = (low / primes[i]) * primes[i];
      if (lolim < low) lolim += primes[i];
      for (long long j = lolim; j < high; j += primes[i]) mark[j - low] = false;
    }
    for (long long j = low; j < high; j++) {
      if (mark[j - low]) primes.push_back(j);
    }
    low += limit;
    high += limit;
  }
}
void ranged_primes(long long low, long long high, vector<long long> &primes) {
  if (low < 2) low = 2;
  if (high < 2) return;
  long long lim = sqrt(high);
  vector<long long> pr;
  linear_sieve(lim, pr);
  if (pr.size() == 0) {
    if (high == 2) {
      primes.push_back(2);
      return;
    }
    if (high == 3) {
      if (low <= 2) {
        primes.push_back(2);
        primes.push_back(3);
        return;
      }
      primes.push_back(3);
      return;
    }
  }
  vector<bool> mark(high - low + 1, true);
  for (auto &i : pr) {
    long long j = i * i;
    if (j < low) {
      j = (low / i) * i;
      if (j < low) j += i;
    }
    while (j <= high) {
      mark[j - low] = false;
      j += i;
    }
  }
  for (long long i = low; i <= high; i++) {
    if (mark[i - low]) primes.push_back(i);
  }
}
long long totient(long long n) {
  long long res = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      res -= res / i;
    }
  }
  if (n > 1) res -= res / n;
  return res;
}
void phi_1_to_n(long long n, vector<long long> &phi) {
  for (long long i = 0; i <= n; i++) {
    phi[i] = i;
  }
  for (long long i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (long long j = i; j <= n; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
}
string division(long long a, long long b) {
  if (a == 0) return "null";
  if (b == 0) return "0";
  string s;
  if (a * b < 0)
    s = "-";
  else
    s = "";
  a = abs(a);
  b = abs(b);
  long long c = gcd(a, b);
  a = a / c;
  b = b / c;
  s += to_string(b);
  s += "/";
  s += to_string(a);
  return s;
}
long long factorial(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) {
    res = (res * i) % 1000000007;
  }
  return res % 1000000007;
}
long long sumofint(long long n) {
  string s = to_string(n);
  long long sum = 0;
  for (long long i = 0; i < s.size(); i++) {
    int j = s[i];
    j -= 48;
    sum += j;
  }
  return sum;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long ans = -1;
  if (sqrt(n) > 10000) {
    for (long long i = sqrt(n) - 10000; i <= sqrt(n); i++) {
      long long temp = i * i + sumofint(i) * i;
      if (temp == n) {
        ans = i;
        break;
      }
    }
    cout << ans;
  } else {
    for (long long i = 1; i <= sqrt(n); i++) {
      long long temp = i * i + sumofint(i) * i;
      if (temp == n) {
        ans = i;
        break;
      }
    }
    cout << ans;
  }
  return 0;
}
