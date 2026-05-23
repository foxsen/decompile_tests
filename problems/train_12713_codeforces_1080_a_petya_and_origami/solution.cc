#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long ans = ceil(n * 2.0 / k) + ceil(n * 5.0 / k) + ceil(n * 8.0 / k);
  cout << ans;
}
