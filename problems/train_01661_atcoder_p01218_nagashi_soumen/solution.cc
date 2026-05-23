#include<bits/stdc++.h>
 
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b))<EPS)
 
using namespace std;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }
 
struct Point {
  double x,y,z;
  Point operator - ( const Point &p ) const { return (Point){x-p.x,y-p.y,z-p.z}; }
  bool operator < ( const Point &p ) const {
    return ( ( !equals(z,p.z) ) ? z > p.z : ( ( !equals(y,p.y) ) ? y < p.y : LT(x,p.x) ) );
  }
};

typedef pair<double,int> ii;

struct Edge{
  int to,cap; double cost; int rev;
  Edge(int to=0,int cap=0,double cost=0,int rev=0):to(to),cap(cap),cost(cost),rev(rev){}
};

const int MAX_V = 1100, IINF = INT_MAX;
int V;
vector<Edge> G[MAX_V];
double h[MAX_V],dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

inline void add_edge(int from,int to,int cap,double cost){
  G[from].push_back(Edge(to,cap,cost,G[to].size()));
  G[to].push_back(Edge(from,0,-cost,G[from].size()-1));
}

double min_cost_flow(int s,int t){
  double res = 0;
  fill(h,h+V,0);
  while(1){
    priority_queue<ii,vector<ii>,greater<ii> > Q;
    fill(dist,dist+V,IINF);
    dist[s] = 0;
    Q.push(ii(0,s));
    while(!Q.empty()){
      ii p = Q.top(); Q.pop();
      int v = p.second;
      if( dist[v] < p.first ) continue;
      for(int i=0;i<G[v].size();i++){
        Edge &e = G[v][i];
        if( LT(0,e.cap) && !equals(dist[v]+e.cost+h[v]-h[e.to],dist[e.to]) && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to] ) { 
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          Q.push(ii(dist[e.to],e.to));
        }
      }
    }
    //if( dist[t] == IINF ) break;
    rep(v,V) h[v] += dist[v];
    if( h[t] >= 0LL ) break;
    int d = IINF;
    for(int v=t;v!=s;v=prevv[v]) d = min(d,G[prevv[v]][preve[v]].cap);
    res += d * h[t];
    for(int v=t;v!=s;v=prevv[v]){
      Edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}


int N,K;
Point ps[100];

const double MAX = 10000;

double getDist(Point p){ return sqrt(p.x*p.x+p.y*p.y+p.z*p.z); }

void compute(){
  if( N <= K ) { puts("0"); return; }
  map<int,int> counter;
  bool failed = false;
  rep(i,N) counter[(int)ps[i].z]++;
  for(map<int,int>::iterator it = counter.begin(); it != counter.end(); it++ ) {
    if( it->second > K ) { failed = true; break; }
  }
  if( failed ) { puts("-1"); return; }
  rep(i,N*4) G[i].clear();
  int source = N * 2;
  int sink = source + 2;
  V = sink +1;
  add_edge(source,source+1,K,0);
  rep(i,N) { 
    add_edge(source+1,i,1,0);
    add_edge(i,N+i,1,-MAX);
    add_edge(N+i,sink,1,0); 
  }

  rep(i,N) rep(j,N) if( i != j && ps[i].z > ps[j].z ){
    add_edge(N+i,j,1,getDist(ps[i]-ps[j]));
  }

  printf("%.10f\n",min_cost_flow(source,sink)+N*MAX);
}

int main(){
  while( cin >> N >> K, N|K ){
    rep(i,N) cin >> ps[i].x >> ps[i].y >> ps[i].z;
    compute();
  }
  return 0;
}