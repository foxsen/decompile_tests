#include <bits/stdc++.h>
using namespace std;
static const int maxn = 5e5 + 6;
int sp[maxn];
vector<int> divisor[maxn];
void seive() {
  for (int i = 2; i < maxn; i++) sp[i] = i;
  for (int i = 2; i < maxn; i++) {
    for (int j = 1; 1LL * i * j < maxn; j++) {
      sp[i * j] = min(sp[i * j], sp[i]);
      divisor[i * j].push_back(i);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  seive();
  int n, q;
  cin >> n >> q;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  vector<int> in_self(n + 1);
  int in_self_cnt = 0;
  vector<int> divi(maxn);
  auto get = [&](vector<int> &vec) {
    int n = vec.size();
    long long coprime = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
      long long d = 1;
      int bitCnt = 0;
      for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) {
          d *= vec[i];
          bitCnt++;
        }
      }
      if (bitCnt & 1)
        coprime += divi[d];
      else
        coprime -= divi[d];
    }
    return coprime;
  };
  long long ans = 0;
  while (q--) {
    int pos;
    cin >> pos;
    vector<int> prime_factors;
    int num = arr[pos];
    while (num > 1) {
      int x = sp[num];
      prime_factors.push_back(x);
      while (num % x == 0) num /= x;
    }
    sort(prime_factors.begin(), prime_factors.end());
    num = arr[pos];
    if (in_self[pos]) {
      for (int d : divisor[num]) divi[d]--;
      in_self[pos] = 0;
      in_self_cnt--;
      ans -= in_self_cnt - get(prime_factors);
    } else {
      ans += in_self_cnt - get(prime_factors);
      for (int d : divisor[num]) divi[d]++;
      in_self[pos] = 1;
      in_self_cnt++;
    }
    cout << ans << endl;
  }
}
