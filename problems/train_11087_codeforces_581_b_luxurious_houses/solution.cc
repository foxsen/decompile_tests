#include <bits/stdc++.h>
using namespace std;
class node {
 public:
  long long int second;
  long long int length;
};
void FastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  FastIO();
  long long int n, i;
  cin >> n;
  long long int a[n], ans[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int maxi = a[n - 1];
  ans[n - 1] = 0;
  for (i = n - 2; i >= 0; i--) {
    ans[i] = max(maxi - a[i] + 1, (long long int)0);
    maxi = max(maxi, a[i]);
  }
  for (i = 0; i < n - 1; i++) cout << ans[i] << " ";
  cout << ans[i] << endl;
  return 0;
}
