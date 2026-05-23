#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, sum = 0;
  vector<int> a;
  cin >> n;
  for (i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
    if (x == 0) sum++;
  }
  sort(a.begin(), a.end());
  for (i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1] && a[i] != 0) sum++;
  }
  cout << (n - sum) << endl;
  return 0;
}
