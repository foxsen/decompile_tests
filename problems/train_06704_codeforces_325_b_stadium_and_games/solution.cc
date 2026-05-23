#include <bits/stdc++.h>
using namespace std;
inline long long tri(long long x) { return x * (x - 1) / 2; }
int main() {
  unsigned long long n;
  cin >> n;
  vector<unsigned long long> teams;
  for (int i = 0; i < 62; i++) {
    unsigned long long tx = (1LL << i) - 1;
    unsigned long long lo = 0, hi = (1LL << min(31, (62 - i)));
    while (hi - lo > 1) {
      unsigned long long mid = (lo + hi) / 2;
      if (tri(2 * mid + 1) + (2 * mid + 1) * tx <= n)
        lo = mid;
      else
        hi = mid;
    }
    if (tri(2 * lo + 1) + (2 * lo + 1) * tx == n)
      teams.push_back((tx + 1) * (2 * lo + 1));
  }
  sort(teams.begin(), teams.end());
  for (int i = 0; i < teams.size(); i++) cout << teams[i] << endl;
  if (!teams.size()) cout << -1 << endl;
  return 0;
}
