#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll dp[2001][2001];
int main(){
    ll n,A[200001];
    cin>>n;
    rep(i,n) cin>>A[i];
    vector<P> B;
    rep(i,n) B.push_back(P(A[i],i));
    sort(all(B));
    rep(i,n)rep(j,n-i) dp[i+1][j]=max(dp[i][j]+abs(j+i-B[i].second)*B[i].first,dp[i][j+1]+abs(j-B[i].second)*B[i].first);
    cout<<dp[n][0]<<"\n";
}
