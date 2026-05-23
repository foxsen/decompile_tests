#include<bits/stdc++.h>
#define int long long
#define float double
#define itn int
#define f(j,n) for(int i=j;i<n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define Endl '\n'
#define ednl '\n'
#define Ednl '\n'
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define mset(arr, i) memset(arr, i, sizeof(arr))
using namespace std;
 
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef priority_queue<int> pqi;
typedef priority_queue<int, vector<int>, greater<int>> pqim;
 
long long binpow(long long a, long long b) { a %= mod; long long res = 1; while (b > 0){if (b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}

int32_t main()
{
    int t1;
    fastio;
    cin>>t1;
    //t1=1;
    while(t1--)
    {
        int n, m;
        cin>>n>>m;
        int a[n];
        f(0,n)cin>>a[i];
        int i;
        for(i=n-1;i>=0;i--)
        {
            if(a[i]!=i+1)
            {
                break;
            }
        }
        i++;
        double prev = 1.0, ans=0.0;
        while(m--)
        {
            int r;
            double p;
            cin>>r>>p;
            if(r>=i)
            {
                ans+=prev*p;
                prev*=((double)1.0-p);
            }
        }
        if(i==0)
        {
            cout<<1.0<<Endl;
        }
        else
        cout<<ans<<endl;
    }
}
