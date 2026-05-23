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
#define bcnt __builtin_popcountll

#define INF 1e16
#define B1 1000000007
#define B2 1000000009

ull mod_pow(ull a,ull n){
  ull res=1;
  while(n){
    if(n&1)res=res*a;
    a=a*a;
    n>>=1;
  }
  return res;
}

string S,T;
vector<ull> hs1,hs2;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>S>>T;
  int N=S.size();
  int M=T.size();
  ull h1=0,h2=0;
  rep(i,M){
    h1*=B1;
    h1+=T[i];
    h2*=B2;
    h2+=T[i];
  }
  rep(i,M){
    ull p1=mod_pow(B1,M-1-i);
    ull p2=mod_pow(B2,M-1-i);
    repl(j,'a','z'+1){
      if(T[i]==j)continue;
      hs1.push_back(h1-p1*T[i]+p1*(ull)j);
      hs2.push_back(h2-p2*T[i]+p2*(ull)j);
    }
    repl(j,'A','Z'+1){
      if(T[i]==j)continue;
      hs1.push_back(h1-p1*T[i]+p1*(ull)j);
      hs2.push_back(h2-p2*T[i]+p2*(ull)j);
    }
  }
  sort(all(hs1)); uni(hs1);
  sort(all(hs2)); uni(hs2);

  h1=0; h2=0;
  ll res=0;
  ull elim1=mod_pow(B1,M),elim2=mod_pow(B2,M);
  rep(i,N){
    h1*=B1;
    h1+=S[i];
    h2*=B2;
    h2+=S[i];
    if(i>=M){
      h1-=elim1*S[i-M];
      h2-=elim2*S[i-M];
    }
    if(i>=M-1&&(*lower_bound(all(hs1),h1))==h1&&(*lower_bound(all(hs2),h2))==h2)res++;
  }
  cout<<res<<endl;

  return 0;
}

