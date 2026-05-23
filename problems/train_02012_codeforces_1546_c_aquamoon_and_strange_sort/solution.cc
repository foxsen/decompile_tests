#include<bits/stdc++.h>
using namespace std;

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define ll                         long long int
#define ld                         long double
#define INF 					   (int)1e9+4
#define INFL                       (ll)1e18+4
#define md                         (int)1e9+7  //use fixed<<setprecion
#define mk                          make_pair
#define pi                         pair<int,int>
#define ss                         second
#define ff                         first
#define pb                         push_back
#define eb                         emplace_back
#define ppcl(x)                   __builtin_popcountll(x)
#define ppc(x)                    __builtin_popcount(x)
#define maxi(a)                   *max_element(a.begin(),a.end());
#define mini(a)                   *min_element(a.begin(),a.end());
#define all(s)                     s.begin(),s.end()
#define rall(x)                   (x).rbegin(), (x).rend()
#define sz(x)                     ((long long)x.size())
#define mez(s)                     memset(s,0,sizeof s)
#define mex(s)                    memset(s,-1,sizeof s)
#define metr(s)                   memset(s,true, sizeof s)
#define rep(i,a,b)                for(int i=a;i<b;i++)
#define fr(i,a,b)                 for(int i=a;i<=b;i++)
#define rrep(i,a,b)               for(int i=a;i>b;i--)
#define rfr(i,a,b)                for(int i=a;i>=b;i--)
//#define INF   1e9+7
typedef vector<int> vi;
typedef vector<vector<int>>vvi;
typedef vector<ll>vl;
typedef map<string,int> mp;
typedef queue<int> que;
typedef vector<pi> vp;
const int mxn=1e5+1;
int odd[mxn],even[mxn],new_odd[mxn],new_even[mxn];
void solve(){
   int n=0,m=0,k=0,x=0,y=0,z=0;
   cin>>n;
   memset(odd,0,sizeof odd);
   memset(even,0,sizeof even);
   memset(new_odd,0,sizeof new_odd);
   memset(new_even,0,sizeof new_even);
   vector<int>a(n);
   for(int i=0;i<n;i++){
   	   cin>>a[i];
   	  if(i%2)odd[a[i]]++;
   	  else even[a[i]]++;
   }
   sort(a.begin(),a.end());
   for(int i=0;i<n;i++){
   	   if(i%2)new_odd[a[i]]++;
   	   else new_even[a[i]]++;
   }
   for(int i=1;i<mxn;i++){
   	if(odd[i]!=new_odd[i] || even[i]!=new_even[i]){
   		cout<<"NO\n";
   		return;
	   }
   }
   cout<<"YES\n";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t=1;
   cin>>t; 
  while(t--){
    solve();
  }
  return 0;
}