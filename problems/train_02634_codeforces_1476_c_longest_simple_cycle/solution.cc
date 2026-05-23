
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	
    ll int t;
    cin>>t;
    while(t--)
    {
     ll int n;
     cin>>n;
     vector<ll int>siz(n),a(n),b(n);
     for(ll int i=0;i<n;i++)
     {
     	cin>>siz[i];
     }
     for(ll int i=0;i<n;i++)
     {
     	cin>>a[i];
     }
     for(ll int i=0;i<n;i++)
     {
     	cin>>b[i];
     	b[i]=abs(b[i]-a[i]);//we have stored the diff instead of b

     }
     //input part has been done
     vector<ll int>dp(n+1,0);
     ll int ans=-1e18,temp=0;
     for(ll int i=1;i<n;i++)
     {

     	if(b[i]==0)
     	{
         temp=0;
     	}
     	else
     	{
     		
         temp=max(temp-b[i],b[i]);
     	}
     	temp+=2+siz[i]-1;
     	ans=max(ans,temp);
     }
   
     cout<<ans<<'\n';
    }
    
    
    return 0;
}