#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  int total = 1;
  for (int &a : A) cin >> a;
  for (int i = 1; i < n; i++) {
    if (A[i] == 0 && A[i - 1] == 0) {
      cout << "-1\n";
      return;
    }
    if (A[i] == 1 && A[i - 1] == 1)
      total += 5;
    else if (A[i] == 1)
      total++;
  }
  cout << total + A[0] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
