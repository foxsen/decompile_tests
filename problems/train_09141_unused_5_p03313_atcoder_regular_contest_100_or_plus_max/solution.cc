#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<int>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<61;
const ll mod=1e9+7;

int main(){
  int i,j;
  int n;
  cin>>n;
  int m=1<<n;
  int a[m];
  for(i=0;i<m;i++){
    cin>>a[i];
  }
  int ans=-1;
  for(i=1;i<m;i++){
    int m1=-1,m2=-1;
    int sub=i;
    do{
      if(m1<=a[sub]){
        m2=m1;
        m1=a[sub];
      }
      else if(m2<=a[sub]) m2=a[sub];
      sub=(sub-1)&i;
    } while(sub!=i);
    if(m1>=0&&m2>=0){
      ans=max(ans,m1+m2);
    }
    cout<<ans<<endl;
  }
}
