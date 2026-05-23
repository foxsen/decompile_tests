#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define int long long int
#define ll long long
#define v4 vector<int>
#define v5 vector < v4 >
#define p4 pair<int,int>
#define F first
#define S second
#define mod 1000000007
#define all(c) c.begin(),c.end()
#define read(v) for(auto &it:v) cin>>it;
#define write(v) for(auto &it:v) cout<<it<<" ";
#define mwrite(m) for(auto &it:m) cout<<it.first<<" "<<it.second<<endl;
const int  N = 2e5 + 5;
void solve() 
{
   int a,b;
   cin>>a>>b;
   string s;
   cin>>s;
   int n=s.length();
   int zc=0,oc=0;
   int ck;
   if(a+b!=n)
   {
   	cout<<"-1"<<endl;
   	return;
   }
   if(n%2==0)
   	ck=n/2;
   else
   	ck=n/2+1;
   for(int i=0;i<ck;i++)
   {
   	  if(s[i]!=s[n-i-1] and s[i]!='?' and s[n-i-1]!='?')
   	  {
   	  	cout<<"-1"<<endl;
   	  	return;
   	  }
   	 if(s[i]=='0' || s[i]=='1' || s[n-i-1]=='0' || s[n-i-1]=='1')
   	 {
   	 	if(s[i]=='0' or s[n-i-1]=='0')
   	 	{
   	 		if(i==n-i-1)
   	 		{
   	 			zc+=1;
   	 		}
   	 		else
   	 			zc+=2;
   	 		s[i]='0';
   	 		s[n-i-1]='0';
   	 	}
   	 	else if(s[i]=='1' or s[n-i-1]=='1')
   	 	{
   	 		if(i==n-i-1)
   	 			oc+=1;
   	 		else
   	 			oc+=2;
   	 		s[i]='1';
   	 		s[n-i-1]='1';
   	 	}
   	 }
   	 //cout<<s<<endl;
   }
   // cout<<s<<endl;
   // cout<<zc<<" "<<oc<<endl;
   if((zc<a and oc>b) || (zc>a and oc<b))
   {
       cout<<"-1"<<endl;
       return;
   }
   else if(zc<=a and oc<=b)
   {
   	   int zl=a-zc;
       int ol=b-oc;
       //cout<<zl<<" "<<ol<<endl;
           for(int i=0;i<n;i++)
           {
           	 if(s[i]=='?' and zl>0)
           	 {
           	 	if(zl>1 and i!=n-i-1)
           	 	{
                  s[i]='0';
           	 	  s[n-i-1]='0';
           	 	  zl-=2;  
           	 	}
           	 	else if(zl==1 and i==n-i-1)
           	 	{
           	 		s[i]='0';
           	 		zl-=1;
           	 	}
           	 }
           	 else if(s[i]=='?' and ol>0)
           	 {
               if(ol>1 and i!=n-i-1)
           	 	{
                  s[i]='1';
           	 	  s[n-i-1]='1';
           	 	  ol-=2;  
           	 	}
           	 	else if(ol==1 and i==n-i-1)
           	 	{
           	 		s[i]='1';
           	 		ol-=1;
           	 	}
           	 }
           }
           //cout<<zl<<" "<<ol<<endl;
        if(zl==0 and ol==0)
        {
           cout<<s<<endl;
           return;
        }
        else
        {
            cout<<-1<<endl;
            return;
        }
   }

}
signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int  t;
    cin >> t;
    while (t--) solve();
    return 0;
}