#include <bits/stdc++.h>
using namespace std;
string s;
vector<long long> v;
long long arr[int(1e6)];
int main() {
  long long T, TT = 1;
  for (T = 1; T <= TT; T++) {
    long long n, i, j, k = 0, m = 0, g, cnt = 1;
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = abs(a[i]);
    }
    sort(a, a + n);
    i = 0;
    j = 1;
    while (i < n && j < n) {
      if (max(abs(a[i] + a[j]), abs(a[i] - a[j])) >=
              max(abs(a[i]), abs(a[j])) &&
          min(abs(a[i] + a[j]), abs(a[i] - a[j])) <=
              min(abs(a[i]), abs(a[j]))) {
        k += (j - i);
        j++;
      } else {
        m = i;
        if (i == j - 1) {
          i++;
          j++;
        } else
          i++;
      }
    }
    cout << k << endl;
  }
  return 0;
}
