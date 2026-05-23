#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; 
        int xr=0;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i],xr^=a[i];
        if(xr==0) 
        cout<<"YES\n";
        else{
            int cnt=0,bnt=0;
            for(int i=0;i<n;i++){
                bnt^=a[i];
                if(bnt==xr) cnt++,bnt=0;
            }
            if(cnt>2) 
            cout<<"YES\n";
            else 
            cout<<"NO\n";
        }
    }
}