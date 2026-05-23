#include<bits/stdc++.h>
using namespace std;
#define MAX_V 1000

int N,a;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

bool dfs(int v){
  used[v]=true;
  for(int i=0;i<(int)G[v].size();i++){
    int u=G[v][i],w=match[u];
    if( w<0 || (!used[w]&&dfs(w)) ){
      match[u]=v;
      match[v]=u;
      return true;
    }
  }
  return false;
}
 
int bipartite_matching(){
  int res=0;
  memset(match,-1,sizeof(match));
  for(int v=0;v<N;v++){
    if(match[v]<0){
      memset(used,false,sizeof(used));
      if(dfs(v))res++;
    }
  }
  return res;
}
 
int main(){
  scanf("%d",&N);
  N--;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%d",&a);
      if(a==1){
        G[j].push_back(N+i);
        G[N+i].push_back(j);
      }
    }
  }

  for(int i=0;i<N;i++)sort(G[i].begin(),G[i].end());
  int f=bipartite_matching();
  printf( f==N?"yes\n":"no\n");
  for(int i=0;i<N&&f==N;i++){
    match[ match[i] ]=-1;
    match[i]=-1;
    memset(used,false,sizeof(used));
    dfs(i);
    G[i].clear();
    G[i].push_back( match[i] );
    G[ match[i] ].clear();
    G[ match[i] ].push_back(i);
    printf("%d\n",match[i]-N+1);
  }
  return 0;
}