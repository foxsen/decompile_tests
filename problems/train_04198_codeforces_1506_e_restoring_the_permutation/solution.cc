#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define gc getchar_unlocked
#define fo(i,n) for( i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;

//=================================================================================
//debugger 
struct myComp {
  constexpr bool operator()(double  const& a,
                           double  const& b) const noexcept {
   
    return a>b;
  }
};
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T> void _print (multiset <T,myComp> v);
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print (multiset <T,myComp> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

//=================================================================================================
ll inf =999999999999999;
unsigned int  md = 1e9+7;

//=================================================================================================

void solve ()
{
  //int i,n;
  //cin>>n;
  
 int n,i;
 cin>>n;
 vi a(n),ans1(n),ans2(n);
 set <int>s;
set <int,greater <int> >s2;
 fo (i,n)
 {cin>>a[i];
 s.insert (i+1);
 s2.insert (i+1);
 }
int j=1;
 fo (i,n)
 {
   if ((i==0)||(a[i-1]!=a[i]))
   {ans1[i]=a[i];
   auto it = s.upper_bound (a[i]);
   it --;
   s.erase(it);
   }
   else 
   {auto it = s.begin();
    ans1[i]=(*it);
    s.erase (it);


   }
 }
 fo (i,n)
 {
   if ((i==0)||(a[i]!=a[i-1]))
   {
     ans2[i]=a[i];
     auto it = s2.upper_bound (a[i]);
    
     it-- ;
      debug (*it);
     s2.erase (it );
   }
   else 
   {
     auto it = s2.upper_bound(a[i]);
     ans2[i]= (*it);
      debug (*it);
     s2.erase (it);

   }
 }
 debug (ans1);
 debug (ans2);
 fo (i,n)
 cout << ans1[i]<<" ";
 cout << "\n";
  fo (i,n)
 cout << ans2[i]<<" ";
 cout << "\n";

}
 
//==================================================================================================
int main ()
{

 #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen ("error.txt","w",stderr);
 #endif 
    
fastio();


int t=1;
cin>>t;
while (t--)
{
    solve ();
}    
                  

}