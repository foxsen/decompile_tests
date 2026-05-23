#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001001001001ll;

int N,P;

int dp[111][111][111];

int latte[111][111];

int X[111],Y[111];
signed main(){
    cin>>N>>P;
    rep(i,N)cin>>X[i]>>Y[i];

    rep(i,N){
        for(int j=i+1;j<=N;j++){
            int pre=0;
            for(int k=i;k<j;k++){
                int x=max(0ll,X[k]-pre);
                pre=max(0ll,Y[k]-x);
            }
            latte[i][j]=pre;
        }
    }

    fill_n(**dp,111*111*111,INF);
    dp[0][0][0]=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(dp[i][j][k]==INF)continue;
                int tmp=latte[i-k][i];

                chmin(dp[i+1][j][0],dp[i][j][k]);
                int x=max(0ll,X[i]-tmp);
                chmin(dp[i+1][j+1][k+1],dp[i][j][k]+max(0ll,Y[i]-x));
            }
        }
    }

    int ans=0;
    rep(i,N+1)rep(j,N+1)if(dp[N][i][j]<=P)chmax(ans,i);
    cout<<ans<<endl;
}