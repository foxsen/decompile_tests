#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int> > g(n + 1);
  if (n * k > n * (n - 1) / 2) {
    cout << -1 << endl;
    exit(0);
  }
  cout << n * k << endl;
  stringstream out;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      int k = (i + j) % n;
      out << i + 1 << " " << k + 1 << endl;
    }
  }
  cout << out.str();
}
