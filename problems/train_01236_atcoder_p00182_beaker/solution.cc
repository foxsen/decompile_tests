#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[50];
bool b[50];

bool pourAll(int p);

bool pour(int p, int q, int rest) {
  if (!rest) {
    return pourAll(p+1);
  }
  if (q == n) {
    return false;
  }
  if (!b[q] && a[q] <= rest) {
    b[q] = true;
    if (pour(p, q+1, rest-a[q])) {
      return true;
    }
    b[q] = false;
  }
  return pour(p, q+1, rest);
}

bool pourAll(int p) {
  if (p == n) {
    return true;
  }
  if (!b[p]) {
    return false;
  }
  if (pour(p, p+1, a[p])) {
    return true;
  }
  return pourAll(p+1);
}

bool solve() {
  sort(a, a+n, greater<int>());
  b[0] = true;
  for (int i=1; i<n; i++) {
    b[i] = false;
  }

  return pourAll(0);
}

int main() {
  bool ans;
  while (1) {
    cin >> n;
    if (!n) {
      break;
    }
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }
    ans = solve();
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}