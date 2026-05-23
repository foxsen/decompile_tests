#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long int a=1,b=1,c=1,ans;
    for(int i=0;i<n;i++){
        a=(a*10)%1000000007;
        b=(b*9)%1000000007;
        c=(c*8)%1000000007;
    }
    ans=(a-2*b+c)%1000000007;
    ans=(ans+1000000007)%1000000007;
    cout<<ans;
    return 0;
}