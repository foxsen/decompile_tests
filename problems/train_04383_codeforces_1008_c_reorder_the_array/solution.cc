#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main() {
  long long n, i, j, t;
  vector<long long> a;
  vector<long long> b;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> j;
    a.push_back(j);
    b.push_back(j);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  i = 0;
  j = 1;
  long long counter = 0;
  while (j < n) {
    if (b[i] < a[j]) {
      t = a[i];
      a[i] = a[j];
      a[j] = t;
      i++;
      counter++;
    }
    j++;
  }
  cout << counter << endl;
}
