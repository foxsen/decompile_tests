#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int M = 1e9;
int a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int common = -1;
  for (int i = 1; i < n; i++) {
    int dif = abs(a[i] - a[i - 1]);
    if (dif == 0) {
      cout << "NO" << endl;
      return 0;
    }
    if (dif == 1) continue;
    if (common == -1) common = dif;
    if (dif != common) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (common == -1) {
    cout << "YES\n" << M << " " << 1 << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    int dif = abs(a[i] - a[i - 1]);
    if (dif == common) continue;
    if (dif == 1 && (a[i] - 1) / common == (a[i - 1] - 1) / common)
      continue;
    else {
      cout << "NO"
           << "\n";
      return 0;
    }
  }
  cout << "YES\n" << M << " " << common << endl;
}
