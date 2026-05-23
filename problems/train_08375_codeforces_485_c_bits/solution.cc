#include <bits/stdc++.h>
using namespace std;
int main() {
  map<long long, long long> mp;
  long long tc, lo, hi, ans;
  for (int i = 0; i < 32; i++) mp[i] = pow(2, i);
  cin >> tc;
  while (tc--) {
    cin >> lo >> hi;
    if (lo == hi) {
      cout << lo << endl;
    } else {
      long long tm = lo;
      vector<int> vec;
      while (tm > 0) {
        vec.push_back(tm % 2);
        tm /= 2;
      }
      long long cnt = 0;
      tm = hi;
      while (tm > 0) {
        cnt++;
        tm /= 2;
      }
      while (vec.size() < cnt) {
        vec.push_back(0);
      }
      long long ans = lo;
      for (int k = 0; k < vec.size(); k++) {
        long long x = (ans | ((long long)1 << k));
        if (vec[k] == 0 && x >= lo && x <= hi) {
          ans = x;
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
