#include<bits/stdc++.h>
#define MAX 1005
#define INF 123456789
using namespace std;
struct edge{int to;int cost;};
typedef pair<int,int> P;
int V;
vector<edge> G[MAX];
int d[MAX];
void dkstr(int s){
  priority_queue<P,vector<P>,greater<P> >que;
  fill(d,d+V,INF);
  d[s]=0;
  que.push(P(0,s));
  while(!que.empty()){
    P p=que.top();que.pop();
    int v=p.second;
    if(d[v]<p.first)continue;
    for(int i=0;i<G[v].size();i++){
      edge e = G[v][i];
      if(d[e.to]>d[v]+e.cost){
	d[e.to]=d[v]+e.cost;
	//cout << d[e.to]<< endl;
	que.push(P(d[e.to],e.to));
      }
    }
  }
}
    
int main(){
  while(1){
    for(int i=0;i<MAX;i++){
      G[i].clear();
    }
    int s,g,m;
    int mp=0;
    cin >> V ;
    if(V==0)break;
    cin >> s >> g >> m;
    s--;
    g--;
    vector<P> ed(m);
    for(int i=0;i<m;i++){
      int b,e;
      cin >> b >> e;
      b--;
      e--;
      ed[i].first=b;
      ed[i].second=e;
      
      edge bu;
      bu.to=e;
      bu.cost=1;
      G[b].push_back(bu);
    }

    dkstr(s);
    int ma=d[g];
    //cout << ma << endl;
    int od[MAX];
    for(int i=0;i<MAX;i++){
      od[i]=d[i];
    }

    for(int i=0;i<m;i++){
      if(od[ed[i].second]<od[ed[i].first]){
	G[ed[i].second].push_back({ed[i].first,1});
	dkstr(s);
	int maa=ma;
	ma=min(ma,d[g]);
	if(maa!=ma){
	  mp=i+1;
	}
	G[ed[i].second].pop_back();
      }
    }
    cout << ma << " " << mp << endl;
  }
  return 0;
}