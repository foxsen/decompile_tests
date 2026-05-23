#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
typedef pair<int,int>P;

int s,t,n,m,a[100009],d[100009];
priority_queue<P,vector<P>,greater<P> >q;
vector<P>v[100009];

signed main(){
  r(i,100009)d[i]=1e15;
  cin>>n>>m>>s>>t; s--; t--;
  r(i,n)cin>>a[i];
  r(i,n-1)v[i+1].push_back(P(i,0));
  r(i,m){
    int q,w;
    cin>>q>>w; q--; w--;
    v[q].push_back(P(w,a[w]));
  }
  q.push(P(0,s));
  while(!q.empty()){
    P p=q.top();q.pop();
    int now=p.second;
    int cost=p.first;
    if(d[now]<cost)continue;
    r(i,v[now].size()){
      int nex=v[now][i].first;
      int ncos=cost+v[now][i].second;
      if(d[nex]<=ncos)continue;
      d[nex]=ncos;
      q.push(P(ncos,nex));
    }
  }
  cout<<d[t]<<endl;
}
