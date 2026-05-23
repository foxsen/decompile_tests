#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const int maxn = 1e6 + 5;
long long k;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> k;
  cin >> s;
  long long tot = 0;
  sort(s.begin(), s.end());
  for (char c : s) {
    tot += c - '0';
  }
  int x = 0;
  for (char c : s) {
    if (tot >= k) out(x);
    x++;
    tot -= c - '0';
    tot += 9;
  }
  assert(tot >= k);
  out(x);
  return 0;
}
