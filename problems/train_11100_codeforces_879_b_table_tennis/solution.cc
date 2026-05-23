#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int p[n], mx = 0;
  std::vector<long long int> v;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    v.push_back(p[i]);
    if (p[i] > mx) mx = p[i];
  }
  for (int i = 0; i < n; i++) {
    int cmp = 1;
    if (p[i] == mx) {
      cout << p[i] << endl;
      break;
    }
    for (int j = 1; j <= k; j++) {
      if (v[i] < v[i + j]) {
        cmp = 0;
        v.push_back(v[i]);
        break;
      }
      v.push_back(v[i + j]);
      if (j == k - 1 && i > 0) break;
    }
    if (cmp == 1) {
      cout << p[i] << endl;
      break;
    }
  }
}
