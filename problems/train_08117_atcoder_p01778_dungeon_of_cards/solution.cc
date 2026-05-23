#include <bits/stdc++.h>
#define MAX_V 40
#define INF 1e5
using namespace std;

/*テヲツ慊?・ツーツ湘ィツイツサテァツ板ィテヲツオツ?テ」ツδッテ」ツδシテ」ツつキテ」ツδ」テ」ツδォテ」ツδ陛」ツδュテ」ツつ、テ」ツδ嘉、ツスツソテァツ板ィ) O(F|V||E|)*/

//ティツセツコテ」ツつ津ィツ。ツィテ」ツ?凖ヲツァツ凝ゥツ??、ツスツ?ティツ。ツ古」ツ?催・ツ?暗」ツ??・ツョツケテゥツ?湘」ツ??」ツつウテ」ツつケテ」ツδ暗」ツ??ゥツ??ィツセツコ)
struct edge{int to, cap,cost,rev;};
int V;                         //テゥツ?づァツつケテヲツ閉ー
vector<edge> G[MAX_V];         //テ」ツつーテ」ツδゥテ」ツδ陛」ツ?ョテゥツ堋」テヲツ篠・テ」ツδェテ」ツつケテ」ツδ暗ィツ。ツィテァツ渉セ
int dist[MAX_V];               //テヲツ慊?ァツ淞ュティツキツ敕ゥツ崢「
int prevv[MAX_V],preve[MAX_V]; //テァツ崢エテ・ツ可催」ツ?ョテゥツ?づァツつケテ」ツ?ィティツセツコ

// fromテ」ツ?凝」ツつ液oテ」ツ?クテ・ツ青妥」ツ?凝」ツ??・ツョツケテゥツ?縦apテ」ツ??」ツつウテ」ツつケテ」ツδ?ostテ」ツ?ョティツセツコテ」ツつ津」ツつーテ」ツδゥテ」ツδ陛」ツ?ォティツソツステ・ツ環?」ツ?凖」ツつ凝」ツ??
void add_edge(int from,int to,int cap,int cost){
  G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
  G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}

//sテ」ツ?凝」ツつ液テ」ツ?クテ」ツ?ョテヲツオツ?ゥツ?叔テ」ツ?ョテヲツ慊?・ツーツ湘ィツイツサテァツ板ィテヲツオツ?」ツつ津ヲツアツづ」ツつ?」ツつ?
//テヲツオツ?」ツ?崚」ツ?ェテ」ツ??・ツ?エテ・ツ青?1テ」ツつ津ィツソツ氾」ツ??
int min_cost_flow(int s,int t,int f){
  int res=0;
  while(f>0){
    //テ」ツδ凖」ツδォテ」ツδ榲」ツδウテ」ツδ陛」ツつゥテ」ツδシテ」ツδ嘉ヲツウツ陛」ツ?ォテ」ツつ暗」ツつ?s-tテゥツ鳴禿ヲツ慊?ァツ淞ュティツキツッテ」ツつ津ヲツアツづ」ツつ?」ツつ?
    fill(dist,dist+V,INF);
    dist[s]=0;
    bool update = true;
    while(update){
      update = false;
      for(int v=0; v<V ;v++){
	if(dist[v]==INF) continue;
	for(int i=0; i<G[v].size(); i++){
	  edge &e = G[v][i];
	  if(e.cap > 0 && dist[e.to] > dist[v]+e.cost) {
	    dist[e.to] = dist[v] + e.cost;
	    prevv[e.to] = v;
	    preve[e.to] = i;
	    update = true;
	  }
	}
      }
    }
    if(dist[t]==INF) return -1; //テ」ツ?禿」ツつ古、ツサツ・テ、ツクツ甘ヲツオツ?」ツ?崚」ツ?ェテ」ツ??」ツ??
    
    //sテ「ツ按稚テゥツ鳴禿ァツ淞ュティツキツッテ」ツ?ォテヲツイツソテ」ツ?」テ」ツ?ヲテァツ崢ョテ、ツクツ?ヲツ敖ッテヲツオツ?」ツ??
    int d = f;
    for(int v=t; v!=s; v=prevv[v])d=min(d,G[prevv[v]][preve[v]].cap);
    f -= d;
    res += d*dist[t];
    for(int v=t; v!=s; v=prevv[v]){
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}

int door[26][10],key[26][10];
int mnalpha[26],mnnum[10];

int S = 26+10,T=S+1;
void mkG(int bit){
  for(int i=0;i<MAX_V;i++)G[i].clear();

  V = 26+10+2;
  //0 -> 25 num
  //26 -> 35 alpha
  
  for(int i=0;i<26;i++)add_edge(S,i,1,0);
  for(int i=0;i<10;i++)add_edge(i+26,T,1,0);

  set<int> used;
  for(int i=0;i<26;i++)
    for(int j=0;j<10;j++){
      if((bit>>j&1)||door[i][j]==0)continue;
      used.insert(i);
    }
  
  for(int i=0;i<26;i++){
    if(used.count(i)==0) add_edge(i,T,1,0);
    else add_edge(i,T,1,mnalpha[i]);
    for(int j=0;j<10;j++){
      if(bit>>j&1)add_edge(i,26+j,1,key[i][j]-mnnum[j]);
    }
  }
}

int main(){
  int n,m;
  cin>>n;
  for(int i=0;i<n;i++){
    char ch;
    int num;
    cin>>ch>>num;
    door[ch-'A'][num] = 1;
  }

  for(int i=0;i<26;i++)for(int j=0;j<10;j++)key[i][j]=INF;
  for(int i=0;i<10;i++) mnnum[i]=INF;
  for(int i=0;i<26;i++) mnalpha[i] = INF;
  
  cin>>m;  
  for(int i=0;i<m;i++){
    char ch;
    int num,cost;
    cin>>ch>>num>>cost;
    key[ch-'A'][num] = min(key[ch-'A'][num],cost);
    mnnum[num] = min(cost,mnnum[num]);
    mnalpha[ch-'A']=min(cost,mnalpha[ch-'A']);
  }

  int ans = INF;
  for(int i=0;i<(1<<10);i++){
    mkG(i);
    int cost=0;
    for(int j=0;j<10;j++)if(i>>j&1) cost+=mnnum[j];
    int res = min_cost_flow(S,T,26);
    if(res!=-1)ans=min(ans,cost+res);
  }
  if(ans>=INF) ans=-1;
  cout<<ans<<endl;
  return 0;
}