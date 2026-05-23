#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const LL INF=1<<17;


int main(){
    int n,t;cin >> n >> t;
    vector<LL> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<vector<LL>> dp(2,vector<LL> (n,0));
    dp[0][0]=h[0];
    dp[1][0]=2*h[0];
    for (int i = 1; i < n; i++) {
        dp[0][i]=dp[0][i-1]+h[i];
    }
    for (int i = 1; i < n; i++) {
        dp[1][i]=max(dp[1][i-1],dp[0][i])+h[i];
    }
    for (int i = 0; i < n; i++) {
        LL ans=(t-dp[0][i])/(dp[1][i]-dp[0][i])+2;
        if(dp[0][i]>t) ans=1;
        cout << ans << endl;
    }
    return 0;
}

