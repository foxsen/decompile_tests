#include<bits/stdc++.h> 
#define int long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define endl "\n"
using namespace std;

const int max_n = 1e3+100;
const int max_value = 1e6+10;
const int inf = 1e18;
const long long Mod = 998244353;

int n,m;
string x,y;
int dp[max_n][max_n][3];

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>x>>y;
    n=x.size();
    m=y.size();

    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){
            for(int prev=0;prev<3;prev++){

                if(prev==0){
                    dp[i][j][prev]=1;
                    
                    if(i<n && (i==0 || (x[i-1]!=x[i]))){
                        dp[i][j][prev]+=dp[i+1][j][0];
                    }
                    if(j<m && (i==0 || (x[i-1]!=y[j]))){
                        dp[i][j][prev]+=dp[i][j+1][1];
                    }

                }else if(prev==1){
                    dp[i][j][prev]=1;

                    if(i<n && (j==0 || (y[j-1]!=x[i]))){
                        dp[i][j][prev]+=dp[i+1][j][0];
                    }
                    if(j<m && (j==0 || (y[j-1]!=y[j]))){
                        dp[i][j][prev]+=dp[i][j+1][1];
                    }

                }else if(prev==2){
                    dp[i][j][prev]=(dp[i+1][j][0]+dp[i][j+1][1])%Mod;
                }

                dp[i][j][prev]%=Mod;
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=dp[i][j][2];
            ans%=Mod;
        }
    }

    int cur=0;
    for(int i=0;i<n;i++){
        if(i>0 && x[i]==x[i-1]){
            int C = ((cur*(cur+1))/2)%Mod;
            C = (C*m)%Mod;
            ans = (ans-C+Mod)%Mod;

            cur=1;
        }else{
            cur++;
        }
    }
    int C = ((cur*(cur+1))/2)%Mod;
    C = (C*m)%Mod;
    ans = (ans-C+Mod)%Mod;

    cur=0;
    for(int i=0;i<m;i++){
        if(i>0 && y[i]==y[i-1]){
            int C = ((cur*(cur+1))/2)%Mod;
            C = (C*n)%Mod;
            ans = (ans-C+Mod)%Mod;

            cur=1;
        }else{
            cur++;
        }
    }
    C = ((cur*(cur+1))/2)%Mod;
    C = (C*n)%Mod;
    ans = (ans-C+Mod)%Mod;


    cout<<ans<<endl;

}