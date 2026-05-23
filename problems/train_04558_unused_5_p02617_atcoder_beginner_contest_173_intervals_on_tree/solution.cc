#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n;
int main()
{
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        ans+=(ll)x*(n-y+1);
    }
    ll res=0;
    for(int i=1;i<=n;i++)
        res+=(ll)i*(n-i+1);
    printf("%lld\n",res-ans);
}
