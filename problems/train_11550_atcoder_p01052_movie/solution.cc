#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > v(n);
  for(int i=0; i<n; i++) {
    vector<int> a(2);
    cin >> a[1] >> a[0];
    v[i]=a;
  }
  sort(v.begin(),v.end());
  for(int i=0; i<n; i++) swap(v[i][0],v[i][1]);
  bool u[n];
  memset(u,0,sizeof(u));
  int ans=0;
  for(int i=1; i<=31; i++) {
    int x=50;
    for(int j=0; j<n; j++) {
      if(v[j][0]<=i&&i<=v[j][1]&&!u[j]) {
        u[j]=1;
        x=100;
        break;
      }
    }
    ans+=x;
  }
  cout << ans << endl;
  return 0;
}
