#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
using namespace std;
int main(){
    int N;
    cin>>N;
    ll p, sum = 0, ans = 0;
    while(N--){
        cin>>p;
        ans+=(p*sum);
        ans%=mod;
        sum+=p;
        sum%=mod;
    }
    cout<<ans%mod;
}
