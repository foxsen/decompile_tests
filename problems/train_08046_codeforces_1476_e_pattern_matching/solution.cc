#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> piii;
typedef pair<ll,pii> ipii;
#define MOD 998244353
#define mod(a) ((a)%MOD)
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<"\n"
#define dbg3(x,y,z) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" , "<<#z<<" = "<<z<<"\n"
#define INF (1LL<<60)
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(),v.end()
#define endl '\n'
ll gcd(ll a,ll b){if(a==0) return b; return gcd(b%a,a);}
ll powm(ll base,ll exp,ll mod=MOD) {base%=mod;ll ans=1;while(exp){if(exp&1LL) ans=(ans*base)%mod;exp>>=1LL,base=(base*base)%mod;}return ans;}


map<string, int> pi;
string p[100005];
string s[100005];
vector<int> ed[100005];
int mt[100005];
int v[100005];

bool check(string a, string b){
   for(int i=0;i<a.size();i++){
       if(a[i]=='_') continue;
       if(a[i]!=b[i]) return false;
   }

   return true;
}

bool dfs(int x, vector<int> &ans){
    if(v[x]==2) return true;
    if(v[x]==1) return false;
    v[x]=1;
    bool flag=1;
    for(auto it:ed[x]) flag&=dfs(it, ans);
    ans.pb(x);
    v[x]=2;
    return flag;
}

int main(){
     sync;
     ll n,m,k;
     cin>>n>>m>>k;

     for(int i=1;i<=n;i++){
         cin>>p[i];
         pi[p[i]]=i;
     }

     for(int i=1;i<=m;i++) cin>>s[i]>>mt[i];     
     
     int flag=1;
     
     for(int i=1;i<=m;i++){
          if(!check(p[mt[i]], s[i])){
              flag=0;break;
          } 
          for(int j=0; j<(1<<k); j++){
              string t=s[i];
              for(int b=0;b<k;b++){
                 if(j&(1<<b)) t[b]='_';
              }
              if(pi.count(t)){
                  if( mt[i]!=pi[t]) ed[mt[i]].pb(pi[t]);
              }
          }
     }
     

     vector<int> ans;
     for(int i=1;i<=n;i++){
          flag&=dfs(i, ans);
     }
     if(!flag) cout<<"NO"<<endl;
     else{
          reverse(ans.begin(), ans.end());
          cout<<"YES"<<endl;
          for(auto it:ans) cout<<it<<" ";
          cout<<endl;
     }
}