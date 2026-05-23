#include <iostream>
using namespace std;
int n,m,s[1000],a[1000],b[1000],ans,dp[1000][1001];
int main(void){
    while(1){
    cin>>n>>m;
    if(n==0&&m==0)return 0;
    ans=1e9;
    for(int i=0;i<n;i++)for(int j=0;j<=n;j++)dp[i][j]=1e9;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++){
        if(a[i]<b[i])s[i]=b[i]-a[i];
        else if(a[i]>b[i])s[i]=m+b[i]-a[i];
        else s[i]=0;
    }
    dp[0][0]=s[0];
    for(int i=1;i<n;i++){
        for(int j=i;j>=0;j--){
            if(s[i]<=s[i-1]){
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
                if(j>0)dp[i][j]=min(dp[i][j],dp[i-1][j-1]+m-s[i-1]+s[i]);
            }
            else{
                dp[i][j]=min(dp[i][j],dp[i-1][j]+s[i]-s[i-1]);
                dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
            }
            //cout<<dp[i][j]<<endl;
        }
    }
    for(int i=0;i<=n;i++){
        ans=min(ans,dp[n-1][i]);
    }
    cout<<ans<<endl;
    }
}

