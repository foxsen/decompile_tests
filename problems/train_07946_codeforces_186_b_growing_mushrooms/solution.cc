#include <bits/stdc++.h>
using namespace std;
const long long NN = 2e5 + 5;
long long n, t1, t2, k;
vector<pair<long long, long long> > isi;
long long cek(long long A, long long B) {
  return A * t2 * 100LL + B * t1 * (100LL - k);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> t1 >> t2 >> k;
  for (long long i = 1; i <= n; i++) {
    long long ta, tb;
    cin >> ta >> tb;
    isi.push_back(make_pair(max(cek(ta, tb), cek(tb, ta)), -i));
  }
  sort(isi.begin(), isi.end());
  reverse(isi.begin(), isi.end());
  for (long long i = 0; i < n; i++) {
    cout << -isi[i].second << " ";
    cout << fixed << setprecision(2) << isi[i].first / 100.00 << "\n";
  }
}
