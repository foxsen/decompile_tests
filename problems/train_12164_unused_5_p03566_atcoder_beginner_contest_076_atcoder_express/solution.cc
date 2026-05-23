#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int T[222];
double V[222];
double M[44444];

int main(){
  int N; cin>>N;
  rep(i,44444) M[i]=101;
  rep(i,N) cin>>T[i];
  rep(i,N) cin>>V[i];
  
  int sum=0;
  rep(i,N){
    T[i]*=2;
    for(int j=sum;j<=sum+T[i];j++){
      M[j]=min(M[j],V[i]);
    }
    sum+=T[i];
  }
  M[0]=M[sum]=0;
  rep(j,sum) M[j+1]=min(M[j+1],M[j]+0.5);
  for(int j=sum-1;j>=0;j--) M[j]=min(M[j],M[j+1]+0.5);

  double ans=0;
  rep(i,sum) ans+=(M[i]+M[i+1]);
  cout<<setprecision(15);
  cout<<ans/4<<endl;
  return 0;
}
