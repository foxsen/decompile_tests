#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<ll,ll,ll> tll;
typedef vector<vector<ll>> mat;
const ll mod=1e9+7;
const int N=5005;
int n,m,a[N],mn[N],mx[N];
ll dp[N][N],ans;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
    if(!m){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx[i]=max(mx[i-1],a[i]);
    }
    mn[n]=1e9;
    for(int i=n-1;i;i--) mn[i]=min(mn[i+1],a[i+1]);
    dp[1][1]=2;
    for(int i=2;i<=n;i++){
        if(a[i]!=mx[i]){
            if(a[i]>=mn[i]) break;
            for(int j=1;j<=m;j++) if(max(j,i-j)<=m) dp[i][j]=dp[i-1][j];
        } else{
            for(int j=1;j<=m;j++) if(max(j,i-j)<=m) dp[i][j]=dp[i-1][j-1];
            if(mx[i-1]<=mn[i]) for(int j=1;j<=m;j++) if(max(j,i-j)<=m) (dp[i][j]+=dp[i-1][i-j])%=mod;
        }
    }
    for(int i=1;i<=m;i++) (ans+=dp[n][i])%=mod;
    cout<<ans<<"\n";
    return 0;
}

