#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
long long int MX = 4000000000000000000;
long long int T;
long long int n;
long long int a[200];
long long int rep[101];
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> T;
  while (T--) {
    memset(rep, 0, sizeof rep);
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) cin >> a[i];
    for (int i = 1; i <= 2 * n; i++) {
      if (rep[a[i]] == 0) {
        cout << a[i] << " ";
      }
      rep[a[i]]++;
    }
    cout << endl;
  }
  return 0;
}
