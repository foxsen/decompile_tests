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
#define mod 1000000007

int N;
int A[1000];

int solve(int k){
  vector<int> a;
  int sum=0;
  rep(i,N){
    if(A[i]%k!=0)continue;
    int tmp=A[i]/k;
    while(tmp%2==0)tmp/=2;
    if(tmp!=1)continue;
    a.push_back(A[i]/k);
    sum+=A[i]/k;
  }
  if((int)a.size()==0)return 0;
  int M=a.size();
  vector<int> dp(sum+1,-1);
  dp[0]=0;
  rep(i,M){
    for(int j=sum-a[i];j>=0;j--){
      if(dp[j]==-1)continue;
      if((j&(a[i]-1))==0&&j+a[i]<=sum)maxch(dp[j+a[i]],dp[j]+1);
    }
  }
  int res=0;
  for(int j=1;j<=sum;j<<=1)maxch(res,dp[j]);
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(1){
    cin>>N;
    if(N==0)break;
    rep(i,N)cin>>A[i];

    int res=0;
    repl(k,1,501){
      maxch(res,solve(k));
    }
    cout<<res<<endl;
  }
  return 0;
}

