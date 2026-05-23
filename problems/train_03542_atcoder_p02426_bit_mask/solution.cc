#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
    using BS = bitset<64>;
    int n;
    cin>>n;
    vector<BS> ms(n);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int x;
            cin>>x;
            ms[i].set(x);
        }
    }

    BS b(0);

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int t,x;
        cin>>t>>x;
        if(t==0) cout<<b[x]<<endl;
        if(t==1) b|= ms[x];
        if(t==2) b&=~ms[x];
        if(t==3) b^= ms[x];
        if(t==4) cout<<((b&ms[x])==ms[x])<<endl;
        if(t==5) cout<<(b&ms[x]).any()<<endl;
        if(t==6) cout<<(b&ms[x]).none()<<endl;
        if(t==7) cout<<(b&ms[x]).count()<<endl;
        if(t==8) cout<<(b&ms[x]).to_ullong()<<endl;
    }

    return 0;
}


