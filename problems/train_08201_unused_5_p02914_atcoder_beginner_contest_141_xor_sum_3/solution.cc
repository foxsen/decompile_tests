#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin >> n;
    int a[n],x=0,b[60]={0};
    for(int i=0;i<n;i++){
        cin >> a[i];
        x^=a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<60;j++){
            if(((1ll<<j)&x) and ((1ll<<j)&a[i]))
                a[i]^=(1ll<<j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=59;j>=0;j--){
            if((1ll<<j)&a[i]){
                if(!b[j])b[j]=a[i];
                a[i]^=b[j];
            }
        }
    }
    int k=0;
    for(int i=59;i>=0;i--){
        k=max(k,k^b[i]);
    }
    cout << k+(x^k);
}