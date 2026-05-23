#include <bits/stdc++.h>
using namespace std;
const int MAXN = 210000;
int fenw[MAXN];
int a[MAXN], ans[MAXN];
int sum(int x) {
  int sum = 0;
  for (; x >= 0; x &= x + 1, --x) sum += fenw[x];
  return sum;
}
void add(int x, int z) {
  for (; x < MAXN; x |= x + 1) fenw[x] += z;
}
int main(int argc, const char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> a[i];
  }
  vector<pair<int, int> > b;
  for (int i = 0; i < (int)(n); ++i) {
    b.push_back(make_pair(a[i], i));
  }
  sort((b).begin(), (b).end());
  for (pair<int, int> p : b) {
    int i = p.second;
    for (int k(1); k * i + 1 < n && k < n; k++) {
      ans[k] += sum(min(k * i + k, n)) - sum(k * i);
    }
    add(i, 1);
  }
  for (int k = 1; k <= (int)(n - 1); ++k) {
    cout << ans[k] << ' ';
  }
  return 0;
}
