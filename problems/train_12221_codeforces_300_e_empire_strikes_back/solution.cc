#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool MinPlace(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool MaxPlace(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename S, typename T>
ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
template <int maxm = 1000005>
class sieve {
 private:
  bool doPhi, doMo;

 public:
  bitset<maxm + 10> isnp;
  vector<int> prime, mo, phi, primes;
  sieve(bool doPhi = false, bool doMo = false) : doPhi(doPhi), doMo(doMo) {
    prime.resize(maxm + 10, 0);
    if (doMo) mo.resize(maxm + 10);
    if (doPhi) {
      phi.resize(maxm + 10);
      for (int i = 0; i <= maxm; i++) phi[i] = i;
    }
    if (doMo) {
      mo[1] = 1;
      mo[2] = mo[3] = -1;
      mo[4] = 0;
    }
    if (doPhi) {
      phi[1] = phi[2] = 1;
      phi[3] = phi[4] = 2;
    }
    prime[1] = 1;
    isnp[1] = true;
    primeWork(2);
    primeWork(3);
    for (int i = 5; i <= maxm; i += 6) {
      for (int j = i; j <= min(i + 2, maxm); j += 2)
        if (!isnp[j]) primeWork(j);
      if (doMo || doPhi)
        for (int j = i; j <= min(i + 5, maxm); j++) {
          bool rem = (j / prime[j]) % prime[j];
          if (doMo) mo[j] = rem * (-mo[j / prime[j]]);
          if (doPhi) phi[j] = phi[j / prime[j]] * (prime[j] - rem);
        }
    }
  }
  void primeWork(long long int pr) {
    prime[pr] = pr;
    primes.push_back(pr);
    for (long long int k = pr * pr; k <= maxm; k += pr) {
      if (!isnp[k]) {
        prime[k] = pr;
        isnp[k] = true;
      }
    }
  }
  bool isprime(int n) {
    assert(n <= maxm);
    return !isnp[n];
  }
};
long long int cnt[int(1e7) + 1] = {};
int a[int(1e7) + 1];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int sum = 0;
  int k, maxm = 0;
  sieve<10000005> s;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + k);
  for (int i = 0, j = 2; i < k; i++) {
    while (a[i] >= j) {
      int no = j++;
      while (no > 1) {
        cnt[s.prime[no]] += (k - i);
        no /= s.prime[no];
      }
    }
  }
  long long int l = 1, r = sum;
  while (l <= r) {
    long long int mid = (l + r) / 2;
    bool cool = true;
    for (auto pr : s.primes) {
      if (pr > a[k - 1]) break;
      long long int target = cnt[pr], test = mid, test_cnt = 0;
      while (test) test_cnt += (test /= pr);
      if (test_cnt < target) {
        cool = false;
        break;
      }
    }
    if (cool)
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << l;
}
