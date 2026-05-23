#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
  list<int>st[1000];
  list<int>::iterator it;
  int n,tc,q,t,s;
  ll x;
  cin>>n>>tc;
  while(tc--)
  {
    cin>>q;
    if(q==0)
    {
      cin>>t>>x;
      st[t].push_back(x);
    }
    else if(q==1)
    {
      cin>>t;
      for(it=st[t].begin();it!=st[t].end();it++)
      {
        if(it!=st[t].begin())cout<<" ";
        cout<<*it;
      }
      cout<<endl;
    }
    else if(q==2)
    {
      cin>>s>>t;
      st[t].splice(st[t].end(),st[s]);
    }
  }
}

