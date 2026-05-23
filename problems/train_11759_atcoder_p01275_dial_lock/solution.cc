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
char s[22],t[22];
int res;

void dfs(int d,int nc){
  int idx=d;
  while(idx<n&&s[idx]==t[idx])idx++;
  if(idx==n){
    minch(res,nc);
    return ;
  }
  if(nc>res)return ;

  int add=(t[idx]-s[idx]+10)%10;
  string tmp;
  repl(i,idx,n)tmp+=s[i];
  repl(i,idx,n){
    s[i]=(char)('0'+(s[i]-'0'+add)%10);
    dfs(idx,nc+1);
  }
  repl(i,idx,n)s[i]=tmp[i-idx];
  return ;
}

int main(){
	cin.sync_with_stdio(false);
  while(1){
    cin>>n;
    if(n==0)break;
    cin>>s>>t;
    res=INF;
    dfs(0,0);
    cout<<res<<endl;
  }
	return 0;
}