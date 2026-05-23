#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  vector<vector<long long>> a(n, vector<long long>(n));
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      bool need = true;
      for(int k=0;k<n;k++) {
        if(k == i || k == j) continue;
        if(a[i][j] < a[i][k] + a[k][j]) continue;
        else if(a[i][j] == a[i][k] + a[k][j]) need = false;
        else {
          ans = -1;
          break;
        }
      }
      if(ans == -1) break;
      if(need) ans += a[i][j];
    }
    if(ans == -1) break;
  }
  cout << ans << endl;
  return 0;
}
