#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int ts;
  cin >> ts;
  while (ts--) {
    long long a, b;
    cin >> a >> b;
    long long mx = max(a, b);
    long long sum = min(a, b) * 2;
    cout << max(mx * mx, sum * sum) << endl;
  }
}
