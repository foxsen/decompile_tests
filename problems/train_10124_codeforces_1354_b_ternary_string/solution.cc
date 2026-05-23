#include <bits/stdc++.h>
using namespace std;
vector<long long int> adj[200001];
vector<pair<long long int, long long int>> path = {
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
long long int P = 1000000007;
long long int MAX = P * (P - 7);
long long int MIN = -1 * MAX;
const int sizes = 200001;
int main() {
  long long int t, n, i, j, k, l, m, o, p, q, r, a, b, c, d;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    n = s.length();
    i = 0;
    j = 0;
    m = 0;
    o = 0;
    p = 0;
    long long int ans = MAX;
    while (i < n && j < n) {
      while ((m == 0 || o == 0 || p == 0) && j < n) {
        if (s[j] == '1') {
          m++;
        }
        if (s[j] == '2') {
          o++;
        }
        if (s[j] == '3') {
          p++;
        }
        j++;
      }
      if (m != 0 && o != 0 && p != 0) ans = min(ans, j - i);
      while (m != 0 && o != 0 && p != 0 && i < j) {
        if (s[i] == '1')
          m--;
        else if (s[i] == '2')
          o--;
        else
          p--;
        if (m != 0 && o != 0 && p != 0) ans = min(ans, j - i);
        i++;
        if (m != 0 && o != 0 && p != 0) ans = min(ans, j - i);
      }
    }
    if (ans == MAX) ans = 0;
    cout << ans << "\n";
  }
  return 0;
}
