#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fr(n) for(ll i=0;i<n;i++)
#define frr(n) for(ll i=n;i>=0;i--)
#define nl printf("\n")
#define debug(arr,n) for(int i=0; i<n; i++) printf("%lld ", arr[i])
#define debugr(arr,s,e) for(int i=s; i<=e; i++) printf("%lld ", arr[i])

int main(){
    ll n,q;
    cin>>n>>q;
    vector<queue<int>>qu(n);
    while(q--){
        ll a,t,x;
        cin>>a;
        if(a==0){
            cin>>t>>x;
            qu[t].push(x);
        }
        else if(a==1){
            cin>>t;
            if(!qu[t].empty()) cout<<qu[t].front()<<endl;
        }
        else{
            cin>>t;
            if(!qu[t].empty()) qu[t].pop();
        }
    }
    return 0;
}
