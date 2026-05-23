#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

int n;
char s[111],sav[111];

int f(int l,int r){
  if(l+1==r){
    return s[l]-'0';
  }
  if(s[l]=='-'){
    return 2-f(l+1,r);
  }
  if(s[l]=='('){
    int level=-1;
    repl(i,l,r){
      if(s[i]=='(')level++;
      else if(s[i]==')')level--;
      if(level==0&&s[i]=='+'){
        return max(f(l+1,i),f(i+1,r-1));
      }
      if(level==0&&s[i]=='*'){
        return min(f(l+1,i),f(i+1,r-1));
      }
    }
  }
  return -1;
}

int main(){
	cin.sync_with_stdio(false);
  while(1){
    cin>>s;
    if(s[0]=='.')break;
    int res=0;
    n=strlen(s);
    rep(p,3)rep(q,3)rep(r,3){
      memcpy(sav,s,sizeof(s));
      rep(i,n){
        if(s[i]=='P')s[i]=p+'0';
        if(s[i]=='Q')s[i]=q+'0';
        if(s[i]=='R')s[i]=r+'0';
      }
      if(f(0,n)==2)res++;
      memcpy(s,sav,sizeof(sav));
    }
    cout<<res<<endl;
  }
	return 0;
}