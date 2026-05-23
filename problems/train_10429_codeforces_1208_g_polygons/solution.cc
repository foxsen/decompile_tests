#include <bits/stdc++.h>
using namespace std;
vector<int> smallest_factor;
vector<int8_t> smallest_power;
vector<int8_t> mobius;
vector<int> totient;
vector<long long> totient_sum;
vector<bool> prime;
vector<int> primes;
void sieve(int maximum) {
  maximum = max(maximum, 2);
  smallest_factor.assign(maximum + 1, 0);
  smallest_power.assign(maximum + 1, 0);
  mobius.assign(maximum + 1, 0);
  totient.assign(maximum + 1, 0);
  prime.assign(maximum + 1, true);
  mobius[1] = 1;
  totient[1] = 1;
  prime[0] = prime[1] = false;
  primes = {};
  for (int i = 2; i <= maximum; i++) {
    if (prime[i]) {
      smallest_factor[i] = i;
      smallest_power[i] = 1;
      mobius[i] = -1;
      totient[i] = i - 1;
      primes.push_back(i);
    }
    for (int p : primes) {
      if (p > smallest_factor[i] || i * p > maximum) break;
      prime[i * p] = false;
      smallest_factor[i * p] = p;
      smallest_power[i * p] =
          smallest_factor[i] == p ? smallest_power[i] + 1 : 1;
      mobius[i * p] = smallest_factor[i] == p ? 0 : -mobius[i];
      totient[i * p] =
          smallest_factor[i] == p ? p * totient[i] : (p - 1) * totient[i];
    }
  }
  totient_sum.assign(maximum + 1, 0);
  for (int i = 1; i <= maximum; i++)
    totient_sum[i] = totient_sum[i - 1] + totient[i];
}
int main() {
  int N, K;
  cin >> N >> K;
  sieve(N);
  if (K == 1) {
    cout << 3 << '\n';
    return 0;
  }
  vector<int> options;
  for (int i = 3; i <= N; i++) options.push_back(totient[i]);
  nth_element(options.begin(), options.begin() + K, options.end());
  long long total = 2;
  for (int i = 0; i < K; i++) total += options[i];
  cout << total << '\n';
}
