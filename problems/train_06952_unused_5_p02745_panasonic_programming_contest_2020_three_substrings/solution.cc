#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 10000;

int main()
{
string v[3];
cin >> v[0] >> v[1] >> v[2] ;
sort(v,v+3);
do{
bool a[5000]={};
bool b[5000]={};
bool c[5000]={};
ll aa=v[0].size();
ll bb=v[1].size();
ll cc=v[2].size();
rep(i,aa)rep(j,bb)if(i+j<aa&&v[0][i+j]!='?'&&v[1][j]!='?'&&v[0][i+j]!=v[1][j]){a[i]=1;break;}
rep(i,aa)rep(j,cc)if(i+j<aa&&v[0][i+j]!='?'&&v[2][j]!='?'&&v[0][i+j]!=v[2][j]){b[i]=1;break;}
rep(i,bb)rep(j,cc)if(i+j<bb&&v[1][i+j]!='?'&&v[2][j]!='?'&&v[1][i+j]!=v[2][j]){c[i]=1;break;}

rep(i,2001)rep(j,2001){
  ll f[3]={aa,bb+i,cc+i+j};
  sort(f,f+3);
  if(!a[i]&&!b[i+j]&&!c[j])ans=min(ans,f[2]);
}
}while(next_permutation(v,v+3));
cout << ans << endl;
return 0;
}