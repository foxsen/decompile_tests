#include <bits/stdc++.h>
using namespace std;
void cs(int i) { cout << "Case " << i << ": "; }
bool comp(pair<long long int, long long int> &a,
          pair<long long int, long long int> &b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}
int main() {
  ios::sync_with_stdio(false);
  long long int t, n, m, p;
  cin >> t;
  while (t--) {
    cin >> n >> m >> p;
    if (n < m) {
      long long int add = m - n + 1;
      if (p >= add) {
        n += add;
        p -= add;
      } else {
        cout << 0 << endl;
        continue;
      }
    }
    if (p == 0) {
      if (n > m)
        cout << 1 << endl;
      else
        cout << 0 << endl;
      continue;
    }
    long long int left = 0, right = p, middle, mn = 0x3f3f3f3f;
    while (left <= right) {
      middle = (left + right) / 2;
      if ((n + middle) > (m + p - middle)) {
        right = middle - 1;
        mn = min(mn, middle);
      } else
        left = middle + 1;
    }
    cout << (p - mn) + 1 << endl;
  }
}
