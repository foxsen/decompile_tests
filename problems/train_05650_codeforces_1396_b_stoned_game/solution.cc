#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7, MAX = 1e6 + 5;
const long long INF = 1e18 + 5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int in = 0; in < 0 + n; in++) cin >> A[in];
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    int xo = A[0];
    int sum = 0;
    for (int i = 1; i < n; i++) {
      xo ^= A[i];
      sum += A[i];
    }
    if (A[0] > sum || xo % 2 == 1) {
      cout << "T" << endl;
    } else
      cout << "HL" << endl;
  }
}
