#include <bits/stdc++.h>
using namespace std;
long long fastpow(long long a, long long b,
                  long long m = (long long)(1e9 + 7)) {
  long long res = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
int32_t main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  long long n, x;
  cin >> n;
  vector<long long> freq(n + 5);
  vector<long long> counts(n + 5);
  for (long long i = 0; i < n; i++) {
    cin >> x;
    freq[x] = i;
  }
  for (long long i = 0; i < n; i++) {
    cin >> x;
    if (freq[x] < i) {
      counts[freq[x] + n - i]++;
    } else {
      counts[freq[x] - i]++;
    }
  }
  cout << *max_element(counts.begin(), counts.end()) << endl;
  return 0;
}
