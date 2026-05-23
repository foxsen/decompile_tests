#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll arr[N],dp[N],br[N];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
        if(i>1) br[i] = br[i-2]+arr[i];
        else br[i]=arr[i];
    }
    for(int i=1; i<n; ++i)
    {
        if(i&1)
            dp[i]= max(br[i-1],dp[i-2]+arr[i]);
        else
            dp[i]= max(dp[i-1],dp[i-2]+arr[i]);
    }
    cout<<dp[n-1]<<endl;
}
