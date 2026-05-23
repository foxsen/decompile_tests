#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int a[2000];
ll dp[18][2000];
ll DP[2][2000];
ll sum[2000];

int main(){
    int n,m,T;cin>>n>>m>>T;
    memset(a,-1,sizeof(a));
    a[0]=0;
    rep(i,n){
        int b;scanf("%d",&b);
        a[b%T]=max(a[b%T],b);
    }
    memset(dp,-1,sizeof(dp));
    rep(i,T){
        dp[0][i]=a[i];
    }
    rep(i,18){
        rep(j,T){
            if(dp[i][j]==-1)continue;   
            rep(k,T){
                if(dp[i][k]==-1)continue;
                dp[i+1][(j+k)%T]=max(dp[i+1][(j+k)%T],dp[i][j]+dp[i][k]);
            }
        }
    }
    memset(DP,-1,sizeof(DP));
    DP[0][0]=0;
    rep(i,18){
        rep(j,T)DP[(i+1)%2][j]=max(DP[(i+1)%2][j],DP[i%2][j]);
        if(!(m>>i&1))continue;
        rep(j,T){
            rep(k,T){
                if(DP[i%2][j]==-1||dp[i][k]==-1)continue;
                DP[(i+1)%2][(j+k)%T]=max(DP[(i+1)%2][(j+k)%T],DP[i%2][j]+dp[i][k]);
            }
		}
	}
	sum[T]=-1;
    for(int i=T-1;i>=0;i--){
        sum[i]=max(DP[0][i],sum[i+1]);
    }
    int q;cin>>q;
    rep(i,q){
        int a,b;scanf("%d%d",&a,&b);
        if(sum[a]>=T*(ll)b){
            puts("yes");
        }
        else puts("no");
    }
}
