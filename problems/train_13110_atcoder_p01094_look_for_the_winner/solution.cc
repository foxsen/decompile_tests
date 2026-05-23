#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    while(true){
        int n,ans,z=0;
        vector<int> alp(26,0),A;
        char c,winner;
        cin>>n;
        if(!n) break;
        rep(i,n){
            cin>>c;
            alp[c-'A']++;
            A=alp;
            sort(A.begin(),A.end(),greater<int>());
            if(!z&&A[0]>A[1]+(n-i-1)){
                ans=i+1;
                rep(j,26) if(alp[j]==A[0]) winner=j+'A';
                z=1;
            }
        }
        if(z) cout<<winner<<" "<<ans<<endl;
        else cout<<"TIE"<<endl;
    }
}
