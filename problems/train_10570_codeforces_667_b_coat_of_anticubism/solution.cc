#include <bits/stdc++.h>
using namespace std;
int q[100000];
int main() {
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    q[i] = x;
  }
  sort(q, q + n);
  int max = q[n - 1];
  for (int i = 0; i < n - 1; i++) {
    max -= q[i];
  }
  cout << max + 1;
}
