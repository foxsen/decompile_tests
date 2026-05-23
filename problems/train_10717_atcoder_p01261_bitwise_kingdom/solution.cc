#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<ll>> C(61,vector<ll>(61,0));

void mk_c(){
  ll mx=61;
  C[0][0]=1;
  for(int i=1;i<mx;i++){
    C[i][0]=1;
    C[i][i]=1;
    for(int t=1;t<i;t++){
      C[i][t]=C[i-1][t-1]+C[i-1][t];
    }
  }
}




int main(){
  mk_c();
  ll n,m;
  while(cin>>n>>m && n){
  ll I=0;
  while(1){
    const ll &c=C[n][I];
    if(c>=m){break;}
    m-=c;
    I++;
  }
  string ans(n,'0');
  ll l=0;
  while(I>0){
    ll c=0;
    if(n-l-1>=0 && I>=0){c=C[n-l-1][I];}
    if(c<m){
      ans[l]='1';
      I--;
      m-=c;
    }
    l++;
  }
  cout<<ans<<endl;

  }

  return 0;
}

