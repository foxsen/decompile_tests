#include <bits/stdc++.h>
const double eps = (1e-9);
using namespace std;
int dcmp(long double a, long double b) {
  return fabsl(a - b) <= eps ? 0 : (a > b) ? 1 : -1;
}
int getBit(int num, int idx) { return ((num >> idx) & 1) == 1; }
int setBit1(int num, int idx) { return num | (1 << idx); }
long long setBit0(long long num, int idx) { return num & ~(1ll << idx); }
long long flipBit(long long num, int idx) { return num ^ (1ll << idx); }
void M() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int countNumBit1(int mask) {
  int ret = 0;
  while (mask) {
    mask &= (mask - 1);
    ++ret;
  }
  return ret;
}
long long arr[300009], even[300009], odd[300009];
vector<int> v, sum;
int fun(long long no) {
  int cnt = 0;
  while (no) {
    cnt += (no % 2);
    no /= 2;
  }
  return cnt;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    int cnt = fun(arr[i]);
    v.push_back(cnt);
  }
  sum.resize(n);
  sum[0] = v[0];
  for (int i = 1; i < ((int)(v).size()); i++) sum[i] = sum[i - 1] + v[i];
  even[0] = (sum[0] % 2 == 0);
  odd[0] = (sum[0] % 2 != 0);
  for (int i = 1; i < n; i++) {
    even[i] = even[i - 1] + (sum[i] % 2 == 0);
    odd[i] = odd[i - 1] + (sum[i] % 2 != 0);
  }
  long long add = 1;
  long long rem = 0, ans = 0, res = 0;
  for (int i = 0; i < n; i++) {
    if (rem % 2 == 0) {
      res += even[n - 1] - even[i + 1 - 1];
    } else {
      res += odd[n - 1] - odd[i + 1 - 1];
    }
    rem += v[i];
    int mx = v[i], s = v[i];
    for (int j = i + 1, k = 0; j < n && k < 65; j++, k++) {
      mx = max(mx, v[j]);
      s += v[j];
      if (s - mx < mx && s % 2 == 0) res--;
    }
  }
  cout << res << endl;
}
