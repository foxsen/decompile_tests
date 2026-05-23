#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int mod = 1e9 + 7;
struct Num {
  int a;
  Num(int _a = 0) : a(_a) {}
  Num operator+(const Num& _) const {
    int ret = a + _.a;
    return ret < mod ? Num(ret) : Num(ret - mod);
  }
  Num operator-(const Num& _) const { return *this + Num(mod - _.a); }
  Num operator*(const Num& _) const { return Num((int)((LL)a * _.a % mod)); }
  void operator+=(const Num& _) { *this = *this + _; }
};
vector<Num> pw2;
int n;
vector<int> x;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  x.assign(n, 0);
  for (int i = 0; i < n; ++i) cin >> x[i];
  sort((x).begin(), (x).end());
  pw2.assign(n, Num(1));
  for (int i = 1; i < ((int)(pw2).size()); ++i) pw2[i] = pw2[i - 1] * Num(2);
  Num ans;
  for (int i = 0; i + 1 < n; ++i) {
    ans += (pw2[i + 1] - Num(1)) * (pw2[n - i - 1] - 1) * Num(x[i + 1] - x[i]);
  }
  cout << ans.a << '\n';
  return 0;
}
