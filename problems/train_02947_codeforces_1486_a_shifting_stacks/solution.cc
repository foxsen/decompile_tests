#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int               long long
#define endl              "\n"
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define vi                vector<int>
#define vpi               vector<pair<int,int>>
#define mii               map<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define repe(i,a,b)        for(int i=a;i<=b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define INF 100000000000000000
#define mod 1000000007
#define esp 10e-7
const int mx=1e2+7;
int a[mx];
bool check(int n)
{
  int sum=0;
  for(int i=0;i<n;i++)
  {
    if(i==0)
      sum+=a[i];
    else
    {
      int tmp=sum+a[i];
      // cout<<tmp<<endl;
      if(tmp<i)
        return false;
      sum=tmp-i;
    }
  }
  return true;
}
signed main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt" , "w" , stderr);
    //#endif 
    IOS
    int t=1,n;
    cin>>t;
   
    while(t--)
    {
      cin>>n;
      
      for(int i=0;i<n;i++)
        {cin>>a[i];}
      
      if(!check(n))
        cout<<"NO"<<endl;
      else
        cout<<"YES"<<endl;
    }
    
    return 0;
}