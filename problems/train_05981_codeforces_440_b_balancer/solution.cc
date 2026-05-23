#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50005;
int n, in[MAXN];
long long k, ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> in[i];
    k += in[i];
  }
  k /= n;
  long long c = in[0] - k;
  for (int i = 1; i < n; ++i) {
    ans += abs(c);
    c += in[i];
    c -= k;
  }
  cout << ans << endl;
  return 0;
}
