#include <bits/stdc++.h>
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
const double PI = acos(-1), EPS = 1e-7;
const int OO = 0x3f3f3f3f, N = 1e7 + 5, mod = 1e9 + 7;
using namespace std;
long long gcd(long long x, long long y) { return (!y) ? x : gcd(y, x % y); }
long long lcm(long long x, long long y) { return ((x / gcd(x, y)) * y); }
void file() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
vector<int> v, vv;
int main() {
  file();
  fast();
  long long n, k;
  cin >> n >> k;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(((v).begin()), ((v).end()));
  for (int i = 1; i * i <= k; i++) {
    if (k % i == 0) {
      vv.push_back(i);
      int j = k / i;
      if (i != j) vv.push_back(j);
    }
  }
  sort(((vv).begin()), ((vv).end()));
  long long mx = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < vv.size(); j++) {
      if (v[i] == vv[j]) {
        mx = v[i];
      }
    }
  }
  cout << k / mx << '\n';
}
