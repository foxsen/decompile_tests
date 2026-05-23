#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 5;
long long a[N];
void solve() {
  int n;
  long long I;
  cin >> n >> I;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long k = (8 * I) / n;
  long long K = pow(2ll, min(20ll, k));
  vector<long long> v;
  vector<long long> psum;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    long long cnt = 0;
    while (j < n && (a[i] == a[j])) {
      j++;
      cnt++;
    }
    v.push_back(a[i]);
    psum.push_back(cnt);
    i = j - 1;
  }
  if (K >= v.size())
    ans = 0;
  else {
    int sz = v.size();
    for (int i = 1; i < sz; i++) psum[i] += psum[i - 1];
    int i = 1, j = K;
    ans = psum[sz - 1] - psum[K - 1];
    while (j < sz) {
      long long temp = psum[sz - 1] - psum[j];
      temp += psum[i - 1];
      ans = min(ans, temp);
      i++;
      j++;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
