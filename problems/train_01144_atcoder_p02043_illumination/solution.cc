#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct Dinic{
  const Int INF=1LL<<55;
  
  struct edge {
    Int to,cap,rev;
    edge(){}
    edge(Int to,Int cap,Int rev):to(to),cap(cap),rev(rev){}
  };

  Int n;
  vector<vector<edge> > G;
  vector<map<Int,int> > M;
  vector<Int> level,iter;

  Dinic(){}
  Dinic(Int sz):n(sz),G(n),M(n),level(n),iter(n){}
  
  void add_edge(Int from,Int to,Int cap){
    M[from][to]=G[from].size();
    M[to][from]=G[to].size();
    G[from].push_back(edge(to,cap,G[to].size()));
    // undirected
    //G[to].push_back(edge(from,cap,G[from].size()-1));
    // directed
    G[to].push_back(edge(from,0,G[from].size()-1));
  }
  
  void bfs(Int s){
    fill(level.begin(),level.end(),-1);
    queue<Int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
      Int v=que.front();que.pop();
      for(Int i=0;i<(Int)G[v].size();i++){
        edge &e = G[v][i];
        if(e.cap>0&&level[e.to]<0){
          level[e.to]=level[v]+1;
          que.push(e.to);
        }
      }
    }
  }
  
  Int dfs(Int v,Int t,Int f){
    if(v==t) return f;
    for(Int &i=iter[v];i<(Int)G[v].size();i++){
      edge &e=G[v][i];
      if(e.cap>0&&level[v]<level[e.to]){
        Int d = dfs(e.to,t,min(f,e.cap));
        if(d>0){
          e.cap-=d;
          G[e.to][e.rev].cap+=d;
          return d;
        }
      }
    }
    return 0;
  }
  
  Int flow(Int s,Int t,Int lim){
    Int fl=0;
    for(;;){
      bfs(s);
      if(level[t]<0||lim==0) return fl;
      fill(iter.begin(),iter.end(),0);
      Int f;
      while((f=dfs(s,t,lim))>0){
        fl+=f;
        lim-=f;
      }
    }
  }

  Int flow(Int s,Int t){
    return flow(s,t,INF);
  }

  //cap==1 only
  bool back_edge(Int s,Int t,Int from, Int to){
    for(Int i=0;i<(Int)G[from].size();i++) {
      edge& e=G[from][i];
      if(e.to==to) {
        if(e.cap==0&&flow(from,to,1)==0) {
          flow(from,s,1);
          flow(t,to,1);
          return 1;
        }
      }
    }
    return 0;
  }
};

//INSERT ABOVE HERE
Int b[55][55];
signed main(){
  Int h,w,c;
  cin>>h>>w>>c;
  for(Int i=0;i<h;i++)
    for(Int j=0;j<w;j++)
      cin>>b[i][j];

  Dinic G(h*w/2+2);
  Int S=h*w/2,T=S+1;

  Int ans=0;
  for(Int i=0;i<h;i++)
    for(Int j=0;j<w;j++)
      ans+=b[i][j];
  
  for(Int i=0;i+1<h;i++){   
    if(i&1){
      for(Int j=1;j<w/2;j++){
        G.add_edge(i*(w/2)+j,T,c);
        
        G.add_edge((i-1)*(w/2)+j-1,i*(w/2)+j,b[i][j*2-1]); 
        G.add_edge((i-1)*(w/2)+j-0,i*(w/2)+j,b[i][j*2-0]); 
        G.add_edge((i+1)*(w/2)+j-1,i*(w/2)+j,b[i+1][j*2-1]); 
        G.add_edge((i+1)*(w/2)+j-0,i*(w/2)+j,b[i+1][j*2-0]); 
      }
    }else{
      for(Int j=0;j<w/2;j++){
        G.add_edge(S,i*(w/2)+j,c);
        if(i==0){
          G.add_edge(i*(w/2)+j,T,b[i][j*2+0]);
          G.add_edge(i*(w/2)+j,T,b[i][j*2+1]);          
        }
        if(i+2==h){
          G.add_edge(i*(w/2)+j,T,b[i+1][j*2+0]);
          G.add_edge(i*(w/2)+j,T,b[i+1][j*2+1]);          
        }
      }
      if(i!=0){        
        G.add_edge(i*(w/2),T,b[i][0]);
        G.add_edge(i*(w/2)+(w/2)-1,T,b[i][w-1]); 
      }
      if(i+2!=h){        
        G.add_edge(i*(w/2),T,b[i+1][0]);
        G.add_edge(i*(w/2)+(w/2)-1,T,b[i+1][w-1]); 
      }
    }    
  }
  
  cout<<ans-G.flow(S,T)<<endl;
  return 0;
}

