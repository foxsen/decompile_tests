#include<bits/stdc++.h>
using namespace std;
typedef pair<vector<int>,int> P;
int n,ans=9;
vector<int> v[2];
map<vector<int>,int> s[2];

void bfs(bool f){
  queue<P> Q;
  Q.push(P(v[f],0));
  while(!Q.empty()){
    P t=Q.front();Q.pop();
    vector<int> b=t.first;
    int d=t.second;
    if(f&&s[0].count(b))ans=min(ans,s[0][b]+d);
    if(s[f].count(b))continue;
    s[f][b]=d;
    if(d==4)continue;
    for(int i=0;i<n;i++)
      for(int j=i+2;j<=n;j++){
	reverse(b.begin()+i,b.begin()+j);
	Q.push(P(b,d+1));
	reverse(b.begin()+i,b.begin()+j);
      }
  }
}

int main(){
  cin>>n;
  for(int i=1,a;i<=n;i++){
    cin>>a;
    v[0].push_back(a);
    v[1].push_back(i);
  }
  bfs(0),bfs(1);
  cout<<ans<<endl;
  return 0;
}