#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 1e18
using namespace std;
int a[1000];
signed main() {
  int N, M;
  while(cin>>N>>M,N+M!=0) {
    for (int i = 0; i < N; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j || a[i]+a[j]>M) continue;
        ans = max(a[i]+a[j], ans);
      }
    }
    if (ans==0) {
      cout << "NONE" << endl;
    } else {
      cout << ans << endl;
    }
    //why i cant use this
    //cout << ((ans==0) ? "NONE" : ans) << endl;
  }
}


