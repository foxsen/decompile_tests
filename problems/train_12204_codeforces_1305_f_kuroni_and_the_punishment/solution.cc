#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
class FKuroniAndThePunishment {
  vector<long long> primes;
  void sieve() {
    int N = 1E6;
    vector<bool> p(N, true);
    for (long long i = 2; i < N; i++) {
      if (p[i]) {
        primes.push_back(i);
        for (long long j = i * i; j < N; j += i) p[j] = false;
      }
    }
  }
  void primeFactor(long long n, set<long long>& s) {
    for (long long Prime : primes) {
      if (Prime * Prime > n) break;
      if (n % Prime == 0) {
        s.insert(Prime);
        while (n % Prime == 0) n /= Prime;
      }
    }
    if (n != 1) s.insert(n);
  }

 public:
  void solve(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    vector<long long> data(n);
    for (long long& x : data) in >> x;
    shuffle(data.begin(), data.end(), rng);
    set<long long> coll;
    for (int i = 0; i < 5 && i < n; i++) {
      coll.insert(data[i]);
      coll.insert(data[i] + 1);
      if (data[i] > 3) coll.insert(data[i] - 1);
    }
    set<long long> check;
    check.insert(2LL);
    sieve();
    for (long long x : coll) {
      primeFactor(x, check);
    }
    long long ans = n;
    for (long long x : check) {
      long long k = 0LL;
      for (long long num : data) {
        if (num < x)
          k += x - num;
        else
          k += min(num % x, x - num % x);
      }
      ans = min(k, ans);
    }
    out << ans << endl;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  FKuroniAndThePunishment solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
