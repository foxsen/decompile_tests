#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define MOD 1000000007

int main()
{
  ll n,m,k;cin>>n>>m>>k;
  vector<int> p(m);
  ll i,j,l;
  rep(i,m)cin>>p[i];
  ll num=1;
  ll needs=0;
  while(num<=k)
  {
    num*=2;
    needs++;
  }
  vector<vector<ll>> con(needs+2,vector<ll>(n,0));
  rep(i,m)
  {
    con[0][p[i]%n]++;
  }
  con[0][0]++;
  for(i=1;i<=needs+1;i++)
  {
    rep(j,n)
    {
      rep(l,n)
      {
        con[i][(j+l)%n]+=con[i-1][l]*con[i-1][j];
        con[i][(j+l)%n]%=MOD;
      }
    }
  }
  ll left=k;
  ll nowi=0;
  vector<ll> ans(n,0);
  ans[0]=1;
  vector<ll> nans(n,0);
  while(left>0)
  {
    if(left%2==1)
    {
      rep(j,n)
      {
        rep(l,n)
        {
          nans[(j+l)%n]+=con[nowi][l]*ans[j];
          nans[(j+l)%n]%=MOD;
        }
      }
      rep(j,n)
      {
        ans[j]=nans[j];
        nans[j]=0;
      }
    }
    left/=2;
    nowi++;
  }
  rep(j,n)cout<<ans[j]<<endl;
}

