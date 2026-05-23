#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const ll inf=1e9+7;


signed  main() {

     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
     ll t;
     cin>>t;
     while(t--)
     {
      string s;
      cin>>s;

      bool a=true;
      for(ll i=0;i<s.length();i++)
      {
        if(a)
        {
          if(s[i]!='a')
          {
            s[i]='a';
          }
          else
          {
            s[i]='b';
          }
          a=false;
        }
        else
        {
          if(s[i]!='z')
          {
            s[i]='z';

          }
          else
          {
            s[i]='y';
          }
          a=true;
        }
        

      }
      cout<<s<<"\n";   
     }

}
