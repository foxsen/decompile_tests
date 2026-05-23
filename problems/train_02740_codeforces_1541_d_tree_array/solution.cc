#include <bits/stdc++.h>
#define nl '\n'
#define pb push_back
#define ll long long
#define VMAX 100001
#define NMAX 35005
#define INF 10000000000000000

using namespace std;
ifstream f("pirati.in");
ofstream g("pirati.out");
const int MOD=1000000007;
int n;
ll dp[205][205];
int dist[205][205];
long long lgpow(ll a,ll b)
{
    ll ans=1,baza=a;
    while(b)
    {
        if(b&1)
        {
            ans=1LL*ans*baza;
            ans%=MOD;
            b--;
        }
        baza=1LL*baza*baza;
        baza%=MOD;
        b/=2;
    }
    return ans;
}
void precalcdp()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0&&j==0)
            {
                dp[i][j]=0;
                continue;
            }
            if(i==0)
            {
                dp[i][j]=1;
                continue;
            }
            if(j==0)
            {
                dp[i][j]=0;
                continue;
            }
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])*lgpow(2,MOD-2);
            dp[i][j]=dp[i][j]%MOD;
        }
    }
}
void RoyFloyd()
{
    for(int i=1;i<=n;i++) dist[i][i]=0;
    for(int aux=1;aux<=n;aux++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][aux]+dist[aux][j]);
            }
        }
    }
}
int main()
{
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           dist[i][j]=2*n+5;
       }
   }
   for(int i=1;i<n;i++)
   {
       int x,y;
       cin>>x>>y;
       dist[x][y]=1;
       dist[y][x]=1;
   }
   RoyFloyd();
   precalcdp();
   long long ans=0;
   for(int lca=1;lca<=n;lca++)
   {
       for(int i=1;i<=n;i++)
       {
           for(int j=i+1;j<=n;j++)
           {
               int x=dist[i][lca];
               int y=dist[j][lca];
               int d=(x+y-dist[i][j])/2;
               x-=d;
               y-=d;
               ans+=dp[y][x];
               ans%=MOD;

           }
       }
   }
   ans=1LL*ans*lgpow(n,MOD-2);
   ans=ans%MOD;
   cout<<ans;


//x

}












