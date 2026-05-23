#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const int INF = pow(10, 7);

int main(){
  int n;cin>>n;
  ll ans=0;
  vector<int> a(n+1);
  for(int i=0;i<=n;i++){
  	cin>>a[i];
  }
  for(int i=0;i<n;i++){
  	int b, d;cin>>b;
    d=min(a[i], b);
    ans+=d;a[i]-= d;b -= d;
    d=min(a[i+1], b);
    ans+=d;a[i+1]-=d;
  }
  cout<<ans<<endl;
}