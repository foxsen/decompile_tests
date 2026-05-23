#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define xx first
#define yy second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) x.size()
#define pii pair<int,int>
#define en '\n'
#define sp ' '
#define smin(a, b) a = min(a, b)
#define smax(a, b) a = max(a, b)
#define ar array
using namespace std;
//const ll mod = 998244353;
const ll mod = 1e9+7;
const int N = 1e5+5e4 + 2;
const int M = 4;
const int inf = 2e9+2;
const ll linf = 8e18+2;
ll add(ll a,ll b){a+=b;return a>=mod?a-mod:a;}
ll mul(ll a,ll b){return (ll)a*b%mod;}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>n(4);
    vector<vector<int>>data(4);
    for(int i=0;i<4;i++)cin>>n[i];
    for(int i=0;i<4;i++){
        data[i].resize(n[i]);
        for(int j=0;j<n[i];j++){
            cin>>data[i][j];
        }
    }
    vector<vector<vector<int>>>a(3);
    for(int i=0;i<3;i++){
        a[i].resize(n[i+1]);
        int m;
        cin>>m;
        for(int j=0,x,y;j<m;j++){
            cin>>x>>y;
            x--,y--;
            a[i][y].pb(x);
        }
    }
    vector<vector<int>>dp(4);
    dp[0]=data[0];
    for(int i=0;i<3;i++){
        dp[i+1].resize(n[i+1],inf);
        multiset<int>s;
        for(int j=0;j<n[i];j++)s.insert(dp[i][j]);
        for(int j=0;j<n[i+1];j++){
            for(auto k : a[i][j])s.erase(s.find(dp[i][k]));
            if(!s.empty())dp[i+1][j]=*s.begin()+data[i+1][j];
            for(auto k : a[i][j])s.insert(dp[i][k]);
        }
    }
    int ans = *min_element(all(dp[3]));
    if(ans>1e9)cout<<"-1\n";
    else cout<<ans<<en;
    return 0;
}
