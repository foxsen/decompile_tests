#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)

signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m),b(m);
    rep(i,m)cin>>a[i]>>b[i];
    
    int start = 0;
    rep(i,m)start += a[i]+1;
    
    vector<int> im(n);
    rep(i,m){
        int pos = b[i]-a[i]-1;
        while(pos<n){
            im[pos] -= b[i];
            pos+=b[i];
        }
    }
    rep(i,im.size()-1){
        im[i+1] += im[i];
    }
    
    rep(i,n){
        cout<<start+im[i]<<endl;
        start += m;
    }
}

