#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16
#define mod 1000000007

ll mod_pow(ll a,ll n){
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll f(ll a){
  ll res=0;
  while(a>0){
    res++; a/=10;
  }
  return res;
}

ll S;

int main(){
  cin>>S;
  ll res=0;
  {
    ll l=1,r=1;
    ll crtS=0;
    for(;f(l)<=7;){
      while(crtS<S){
        crtS+=f(r);
        r++;
      }
      if(crtS==S){
        res++;
      }
      crtS-=f(l);
      l++;
    }
  }
  res%=mod;

  {
    repl(i,1,S/8+1){
      if(S%i!=0)(res+=1)%=mod;
      else{
        ll nd=(9*mod_pow(10,(S/i)-1)%mod-i+1+mod)%mod;
        (res+=nd)%=mod;
      }
    }
  }

  cout<<res%mod<<endl;

  return 0;
}
