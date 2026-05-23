#include <bits/stdc++.h>
using namespace std;
const long long N = 1e14;
const long long oo = (1ll << 63) - 1;
long long a, b, ab;
vector<long long> A, B, AB;
int tknp(const long long& a, const long long& b) {
  int l = lower_bound(AB.begin(), AB.end(), a) - AB.begin(), r = AB.size() - 1;
  while (l < r) {
    int m = l + r + 1 >> 1;
    if (ab / AB[m] < b)
      r = m - 1;
    else
      l = m;
  }
  return AB[l] >= a && ab / AB[l] >= b ? l : -1;
}
long long sol() {
  long long res = oo;
  for (int i = 0, _n = (A.size()); i < _n; i++) {
    long long x = A[i], y = a / x;
    long long t = tknp(x, y);
    if (t < 0) continue;
    res = min(res, AB[t] + ab / AB[t]);
  }
  return res;
}
void calc() {
  long long lim = sqrt(a + b);
  for (long long i = 1; i <= lim; i++) {
    if (a % i == 0) A.push_back(i);
    if (b % i == 0) B.push_back(i);
    if (ab % i == 0) AB.push_back(i);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(AB.begin(), AB.end());
}
int main() {
  cin >> a >> b;
  ab = a + b;
  calc();
  long long t1 = sol();
  swap(a, b);
  swap(A, B);
  cout << min(t1, sol()) * 2;
}
