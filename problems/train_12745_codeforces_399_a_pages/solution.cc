#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  if (k - m > 1 && k + m < n) {
    cout << "<< ";
    for (int i = k - m; i <= k + m; i++) {
      if (i == k) {
        cout << "(" << i << ") ";
      } else {
        cout << i << " ";
      }
    }
    cout << ">>";
  }
  if (k - m <= 1 && k + m >= n) {
    for (int i = 1; i <= n; i++) {
      if (i == k) {
        cout << "(" << i << ") ";
      } else {
        cout << i << " ";
      }
    }
  }
  if (k - m <= 1 && k + m < n) {
    for (int i = 1; i <= k + m; i++) {
      if (i == k) {
        cout << "(" << i << ") ";
      } else {
        cout << i << " ";
      }
    }
    cout << ">>";
  }
  if (k - m > 1 && k + m >= n) {
    cout << "<< ";
    for (int i = k - m; i <= n; i++) {
      if (i == k) {
        cout << "(" << i << ") ";
      } else {
        cout << i << " ";
      }
    }
  }
}
