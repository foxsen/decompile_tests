#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define l(i,a,b) for(lli i=a;i<b;i++)
#define lr(i,a,b) for(lli i=a;i>=b;i--)
#define sl(i,m) for(auto i= m.begin();i!=m.end();++i)
#define ll long long
#define lli long long int
#define ld long double
#define vec vector<int>
#define mii map<long int,long int>
#define vl vector<long long>
#define se set <long long int>
#define pi pair<long long,long long>
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define tc lli te;i(te);l(t,1,te+1)
#define all(v) v.begin(), v.end()
#define i(x) cin>>x
#define o(x) cout<<x
#define N 300000
#define mod 1000000007
#define nl cout<<"\n";
#define SYNC ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    SYNC
    tc
    {
        lli n,ans=1e17;
        i(n);
        string s;
        i(s);
        vl post(n+1,0),count(n+1,0);
        l(i,0,n)
        {
            if(s[i]=='*')
            {
                post[i+1]=post[i]+i;
                count[i+1]=count[i]+1;
            }
            else
            {
                post[i+1]=post[i];
                count[i+1]=count[i];
            }
        }
        l(i,0,n)
        {
            if(s[i]=='*')
            {
                lli cnt=count[n]-count[i+1];
                lli right=post[n]-post[i+1]-cnt*i-(cnt*(cnt+1))/2;
                lli left=count[i]*i-post[i]-(count[i]*count[i+1])/2 ;
                ans=min(ans,left+right);
            }
        }
        if(ans==1e17)
            ans=0;
        o(ans);
        nl
    }
}
