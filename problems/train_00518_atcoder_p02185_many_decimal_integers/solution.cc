#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=1e9;
const long long LINF=1e18;
#define int long long
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
int pw(int n,int k){
  if(k<0)return pw(n,k+MOD-1);
  int res=1;
  while(k){
    if(k&1)res*=n;
    res%=MOD;
    n*=n;n%=MOD;
    k>>=1;
  }
  return res;
}
//main
signed main(){
  string s,t;cin>>s>>t;
  int N=s.size();
  std::vector<int> v(223456),a(223456);
  std::vector<int> w(11);
  w[0]=0;
  for(int i=1;i<=10;i++)w[i]=w[i-1]+i;
  reverse(t.begin(),t.end());

  a[0]=1;
  for(int i=0;i<N;i++){
    if(t[i]=='?')a[i+1]=a[i]*10%MOD;
    else a[i+1]=a[i];
    a[i+1]%=MOD;
  }

  v[0]=0;
  int now=1;
  for(int i=0;i<N;i++){
    if(t[i]=='?')v[i+1]=v[i]*10%MOD+w[9]*now%MOD*a[i];
    else v[i+1]=v[i]*1+(t[i]-'0')*now%MOD*a[i]%MOD;
    now*=10;now%=MOD;
    v[i+1]%=MOD;
  }

  reverse(t.begin(),t.end());

  int gyaku=pw(10,MOD-2);
  now=pw(10,N-1);

  int ans=0,res=0,flg=0;
  for(int i=0;i<N;i++){
    //cout<<i<<" "<<ans<<endl;
    int j=s[i]-'0';
    //cout<<i<<" "<<j<<endl;
    if(t[i]=='?'){
      if(j>0){
        ans+=res*j%MOD*a[N-i-1]%MOD;
        ans+=w[j-1]*now%MOD*a[N-i-1]%MOD;
        ans+=v[N-i-1]*j%MOD;
        ans%=MOD;
      }
      res+=j*now%MOD;
      res%=MOD;
      now*=gyaku;
      now%=MOD;
      continue;
    }

    if(s[i]<t[i]){
      flg=1;
      break;
    }

    if(s[i]>t[i]){
      ans+=res*a[N-i-1];
      ans+=(t[i]-'0')*now%MOD*a[N-i-1]%MOD;
      ans+=v[N-i-1];
      ans%=MOD;
      flg=1;
      break;
    }

    assert(s[i]==t[i]);
    res+=j*now%MOD;
    res%=MOD;
    now*=gyaku;
    now%=MOD;
  }

  if(!flg) ans+=res;
  ans%=MOD;

  //for(int i=0;i<5;i++)cout<<v[i]<<" ";cout<<endl;
  //for(int i=0;i<5;i++)cout<<a[i]<<" ";cout<<endl;
  fin(ans);
}

