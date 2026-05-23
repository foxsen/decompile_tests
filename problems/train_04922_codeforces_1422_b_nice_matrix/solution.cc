#include <bits/stdc++.h>
using namespace std;
void testcase() {
  long long n, m, change = 0, r1, r2, c1, c2;
  cin >> n >> m;
  vector<vector<long long>> a(n, vector<long long>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  for (int i = 0; i < (n + 1) / 2; i++) {
    for (int j = 0; j < (m + 1) / 2; j++) {
      c1 = j, c2 = m - j - 1;
      r1 = i, r2 = n - i - 1;
      long long avg;
      vector<long long> mid;
      mid.push_back(a[r1][c1]);
      mid.push_back(a[r1][c2]);
      mid.push_back(a[r2][c1]);
      mid.push_back(a[r2][c2]);
      sort(mid.begin(), mid.end());
      avg = mid[mid.size() / 2];
      if (r1 != r2) {
        if (c1 != c2)
          change += abs(a[r1][c1] - avg) + abs(a[r1][c2] - avg) +
                    abs(a[r2][c1] - avg) + abs(a[r2][c2] - avg);
        else {
          change += abs(a[r1][c1] - avg) + abs(a[r2][c1] - avg);
        }
      } else {
        if (c1 != c2) change += abs(a[r1][c1] - avg) + abs(a[r1][c2] - avg);
      }
    }
  }
  cout << change << endl;
}
int main() {
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    testcase();
  }
}
