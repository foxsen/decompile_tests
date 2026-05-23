#include <bits/stdc++.h>
using namespace std;
bool value_comparer(map<long long, long long>::value_type &i1,
                    map<long long, long long>::value_type &i2) {
  return i1.second < i2.second;
}
const int MOD = 1e9 + 7;
const int nax = 1e6 + 10;
vector<int> tree(4 * nax);
int i, j, x, y, k;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
class bitmask {
 public:
  void PowerSet(char *set, int set_size) {
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
    for (counter = 0; counter < pow_set_size; counter++) {
      for (j = 0; j < set_size; j++) {
        if (counter & (1 << j)) cout << set[j];
      }
      cout << endl;
    }
  }
};
long long powerLL(long long x, long long n) {
  long long result = 1;
  while (n) {
    if (n & 1) result = result * x % MOD;
    n = n / 2;
    x = x * x % MOD;
  }
  return result;
}
int32_t main() {
  long long n, sum = 0;
  cin >> n;
  map<long long, long long> m;
  for (int i = 0; i < n; i++) {
    long long val;
    cin >> val;
    m[val - i] += val;
  }
  map<long long, long long>::iterator itor =
      max_element(m.begin(), m.end(), value_comparer);
  cout << itor->second << endl;
}
