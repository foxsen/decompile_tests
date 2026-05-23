#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD1=1e9+7;
const int MOD2=998244353;
const ll INF=LLONG_MAX;
const ld PI=3.14159265358979323846;
ll gcd(ll a,ll b){if(b==0) return a; return gcd(b,a%b);}
ll fpow(ll a,ll b,ll m)
{
    if(!b) return 1;
    ll ans=fpow(a*a%m,b/2,m);
    return (b%2?ans*a%m:ans);
}
ll inv(ll a,ll m) {return fpow(a,m-2,m);}
#define MottoHayaku ios::sync_with_stdio(false);cin.tie(0);
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define repk(i,m,n) for(int i=m;i<n;i++)
#define F first
#define S second
#define pb push_back
#define SZ(a) ((ll)a.size())
#define reset(a) memset(a,0,SZ(a))
#define cd(a,b) ((a+b-1)/b)
#define pow2(a) (1LL<<a)
#define LB(a,x) (lower_bound(a.begin(),a.end(),x))
#define LPOS(a,x) (lower_bound(a.begin(),a.end(),x)-a.begin())
#define UB(a,x) (upper_bound(a.begin(),a.end(),x))
#define UPOS(a,x) (upper_bound(a.begin(),a.end(),x)-a.begin())
#define uni(c) c.resize(distance(c.begin(),unique(c.begin(),c.end())))
#define unisort(c) sort(c.begin(),c.end()),uni(c)
vector<ll> pos[300005];
ll cnt[300005];
set<ll> s,st;
int main()
{
    MottoHayaku
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        rep1(i,n) pos[i].clear(),cnt[i]=0;
        rep1(i,n)
        {
            ll k;
            cin>>k;
            pos[k].pb(i);
            cnt[k]++;
            s.insert(k);
        }
        st.insert(0);
        st.insert(n+1);
        bool x=0;
        vector<ll> ans;
        ll mn=INF;
        rep1(i,n)
        {
            if(cnt[i]==0) x=1;
            if(x)
            {
                ans.pb(0);
                continue;
            }
            bool y=0;
            ll d=pos[i].back()-pos[i][0]+1;
            for(ll id:pos[i])
            {
                auto it=st.lower_bound(id);
                ll pos2=*it;
                it--;
                ll pos1=*it;
                mn=min(mn,pos2-pos1-1);
                if(mn>=n-i+1&&mn>=d) y=1;
            }
            for(ll id:pos[i]) st.insert(id);
            if(y) ans.pb(1);
            else ans.pb(0);
        }
        for(int i=ans.size()-1;i>=0;i--) cout<<ans[i];
        cout<<"\n";
        st.clear(),s.clear();
    }
}
