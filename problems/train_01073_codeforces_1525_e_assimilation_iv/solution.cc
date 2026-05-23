#include<bits/stdc++.h>

using namespace std;
const int nn =5100;
const int inff = 0x3fffffff;
const double eps = 1e-8;
typedef long long LL;
const double pi = acos(-1.0);
const LL mod = 998244353;
int n,m;
LL POW(LL x,LL y)
{
    LL ret=1;
    while(y)
    {
        if(y&1)
            ret=(ret*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return ret;
}
int d[25][51000];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            scanf("%d",&d[i][j]);
    }
    LL jc=1;
    for(int i=1;i<=n;i++)
        jc=(jc*i)%mod;
    LL tem=0;
    for(int i=1;i<=m;i++)
    {
        vector<int>ve;
        for(int j=1;j<=n;j++)
            ve.push_back(d[j][i]);
        sort(ve.begin(),ve.end());
        LL num=1;
        for(int j=0;j<n;j++)
        {
            LL chose = max(0,ve[j]-1-j);
            num=(num*chose)%mod;
        }
        tem=(tem+num)%mod;
    }
    LL ans=(m*jc-tem)%mod;
    ans=(ans+mod)%mod;
    ans=(ans*POW(jc,mod-2))%mod;
    cout<<ans<<endl;
    return 0;
}
