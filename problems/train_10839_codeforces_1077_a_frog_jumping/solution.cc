#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, a, b, k;
  cin >> n;
  while (n--) {
    cin >> a >> b >> k;
    cout << (a * (k - (k / 2)) - b * (k / 2)) << endl;
  }
}
