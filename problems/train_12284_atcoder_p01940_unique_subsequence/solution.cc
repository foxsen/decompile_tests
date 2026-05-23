#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  string t,p;cin>>t>>p;
  int nowi=0;
  vector<int> use_front(0);
  vector<int> use_back(0);
  int i;
  rep(i,t.size())
  {
    if(t[i]==p[nowi])
    {
      use_front.emplace_back(i);
      nowi++;
    }
    if(nowi>=p.size())break;
  }
  nowi=p.size()-1;
  for(i=t.size()-1;i>=0;i--)
  {
    if(t[i]==p[nowi])
    {
      use_back.emplace_back(i);
      nowi--;
    }
    if(nowi<0)break;
  }
  if(use_front.size()<p.size()||use_back.size()<p.size())
  {
    cout<<"no"<<endl;
  }
  else
  {
    reverse(all(use_back));
    if(use_back==use_front)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
  
}

