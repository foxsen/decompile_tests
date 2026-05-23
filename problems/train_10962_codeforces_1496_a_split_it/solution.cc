#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define mk make_pair
#define MOD 1000000007

int main()
{    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ll t;
     cin>>t;
     //t=1;
     while(t--)
     {
          ll n,k;
          cin>>n>>k;
          string s;
          cin>>s;
         // stirng = a;
          ll index = (n+1)/2-1;
          ll count=0;
          ll i=0;
          while(s[n-1-i]==s[i] && i<index)
          {
               i++;
               count++;
          }
          if((k<count+1) || k==0)
          cout<<"YES\n";
          else
          cout<<"NO\n";
     }
}