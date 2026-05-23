#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef unordered_map<int,int> umii;
typedef unordered_map<ll, ll> umll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
 
#define      unsigned long long int ull
#define      fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define      F first
#define      S second
#define      f(i,n) for (int i = 0; i < n; i++)
#define      fr(i,n) for(int i=(int)n-1;i>=0;--i)
#define      fo(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define      pb push_back
#define      mkp make_pair
#define      pri_que_down priority_queue<ll>
#define      pri_que_up  priority_queue<ll, vector<ll>, greater<ll> >
 void Prime(ll n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}
void solve() 
{
   ll n,m;
   cin>>n;
   vl a(n);
   ll i;
   f(i,n)
   cin>>a[i];
   ll  sum=0;
   f(i,n)
   sum+=a[i];
   ll x=*max_element(a.begin(),a.end());
   if(sum%n==0)
   {
   	  ll p=sum/n;
   	  ll c=0;
   	  f(i,n)
   	  {
   	  	if(a[i]>p)
   	  	c++;
      }
      cout<<c<<endl;
   }
   else
   {
   	cout<<"-1"<<endl;
   }
}
int main()
{ 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t;
cin>>t;
while(t--)
{
solve();
}
return 0;
}