#include <bits/stdc++.h>
using namespace std;
const int kNmax = 2e5 + 10;
const int kMod = 998244353;
int n, p[kNmax];
int emptyLeft[kNmax], emptyRight[kNmax];
int countBigger[kNmax], countSmaller[kNmax];
int res;
bool seen[kNmax];
class FT {
 public:
  FT(int n) {
    sz_ = n;
    arr_.resize(sz_ + 5);
  }
  int lsb(int x) { return (x & (x - 1)) ^ x; }
  void update(int pos) {
    for (; pos <= sz_; pos += lsb(pos)) {
      arr_[pos]++;
    }
  }
  int query(int pos) {
    int res = 0;
    for (; pos > 0; pos -= lsb(pos)) {
      res += arr_[pos];
    }
    return res;
  }
  vector<int> arr_;
  int sz_;
};
FT* ft;
int fastPow(int n, int p) {
  if (!p) {
    return 1;
  }
  if (p % 2) {
    return (1LL * n * fastPow(n, p - 1)) % kMod;
  }
  int tmp = fastPow(n, p / 2);
  return (1LL * tmp * tmp) % kMod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  ft = new FT(n);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    if (p[i] == -1) {
      emptyLeft[i]++;
      emptyRight[i]++;
      continue;
    }
    seen[p[i]] = true;
  }
  int cntUnknown = 0;
  for (int i = 1; i <= n; i++) {
    if (!seen[i]) {
      cntUnknown++;
      countBigger[i]++;
      countSmaller[i]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    countSmaller[i] += countSmaller[i - 1];
    emptyLeft[i] += emptyLeft[i - 1];
  }
  for (int i = n; i; i--) {
    countBigger[i] += countBigger[i + 1];
    emptyRight[i] += emptyRight[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    if (p[i] != -1) {
      res = (res + ft->query(n) - ft->query(p[i])) % kMod;
      ft->update(p[i]);
      int exp = (1LL * countSmaller[p[i]] * emptyRight[i]) % kMod;
      exp = (1LL * exp * fastPow(cntUnknown, kMod - 2)) % kMod;
      res = (res + exp) % kMod;
      exp = (1LL * countBigger[p[i]] * emptyLeft[i]) % kMod;
      exp = (1LL * exp * fastPow(cntUnknown, kMod - 2)) % kMod;
      res = (res + exp) % kMod;
    }
  }
  int exp = (1LL * cntUnknown * (cntUnknown - 1)) % kMod;
  exp = (1LL * exp * fastPow(4, kMod - 2)) % kMod;
  res = (res + exp) % kMod;
  cout << res;
}
