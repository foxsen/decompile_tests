#include <iostream>
using namespace std;
typedef long long int ll;
ll mod;
ll dp[2][201][11][(1<<11)];
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,K; cin >> N >> K >> mod;
    dp[0][0][1][1]=1;
    int kk=(1<<(1+K));
    for(int _=0;_<N;_++){
        for(int i=0;i<=2*N;i++){
            for(int j=0;j<=K;j++){
                for(int k=0;k<kk;k++){
                    dp[1][i][j][k]=0;
                }
            }
        }
        for(int i=0;i<2*N;i++){
            for(int j=1;j<=K;j++){
                for(int k=0;k<kk;k++){
                    if(dp[0][i][j][k]==0)continue;
                    int t=0;
                    while((k>>t)&1)t++;
                    if(t>K)continue;
                    int ii=i+t;
                    int kkk=(k>>t)+1;
                    for(int jj=1;jj<=K;jj++){
                        if((kkk>>jj)&1)continue;
                        if(ii+jj-i-j>K)continue;
                        if(i+j<ii+jj&&ii+jj<=2*N)(dp[1][ii][jj][kkk|(1<<jj)]+=dp[0][i][j][k])%=mod;
                    }
                }
            }
        }
        for(int i=0;i<=2*N;i++){
            for(int j=1;j<=K;j++){
                for(int k=0;k<kk;k++){
                    dp[0][i][j][k]=dp[1][i][j][k];
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<2*N;i++){
        for(int j=1;j<=K;j++){
            for(int k=0;k<kk;k++){
                (ans+=dp[0][i][j][k])%=mod;
            }
        }
    }
    cout << ans << endl;
}
