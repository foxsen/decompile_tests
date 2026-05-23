#include <bits/stdc++.h>
using namespace std;
long long arrm[2000010];
int main() {
  long long n, i;
  cin >> n;
  long long l[n + 10], maxi = 0;
  for (i = 0; i < n; i++) {
    cin >> l[i];
    for (long long j = 0; j < l[i]; j++) {
      long long x;
      cin >> x;
      arrm[i] = max(arrm[i], x);
    }
    maxi = max(maxi, arrm[i]);
  }
  long long ans = 0;
  for (i = 0; i < n; i++) {
    ans += (maxi - arrm[i]) * l[i];
  }
  cout << ans << endl;
}
