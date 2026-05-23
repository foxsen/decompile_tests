#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    
    
    multiset<int> st;
    vector<int> ans;
    rep(k,n){
        if(st.count(-a[k])==0){
            st.insert(a[k]);
        }else{
            st.erase(st.find(-a[k]));
        }

        if(st.count(a[n-k-1])==0){
            st.insert(-a[n-k-1]);
        }else{
            st.erase(st.find(a[n-k-1]));
        }
        
        if(st.size()==0)ans.pb(k);
    }
    rep(i,ans.size()){
        if(i)cout<<" ";
        cout<<ans[i]+1;
    }
    cout<<endl;
}

