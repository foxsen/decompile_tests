#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0403"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif

#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct ChebyshevNeighbors{
  struct Point{
    T x,y;
    int idx,idy;
    Point(){}
    Point(T x,T y,int idx):x(x),y(y),idx(idx),idy(-1){}
    bool operator<(const Point &a)const{
      if(y!=a.y) return y>a.y;
      return x<a.x;
    }
  };

  vector<T> xs,ys;
  ChebyshevNeighbors(vector<T> xs,vector<T> ys):xs(xs),ys(ys){}

  vector<Point> ps,bk;

  void chk(int idx,int j){
    if(idx<0) return;
    int &idy=ps[j].idy;
    if(idy<0||xs[idy]<xs[idx]) idy=idx;
  }

  void upd(int &idx,int i){
    if(idx<0||xs[idx]<ps[i].x) idx=ps[i].idx;
  }

  void dfs(int l,int r){
    if(l+1==r) return;
    int m=(l+r)>>1;
    dfs(l,m);dfs(m,r);

    {
      int i=l,j=m,idx=-1;
      while(i<m||j<r){
        if(i==m||j==r){
          if(i==m) chk(idx,j++);
          if(j==r) upd(idx,i++);
          continue;
        }
        ps[i].x+ps[i].y<=ps[j].x+ps[j].y?upd(idx,i++):chk(idx,j++);
      }
    }

    {
      int i=l,j=m,k=l;
      for(int i=l;i<r;i++) bk[i]=ps[i];
      while(i<m||j<r){
        if(i==m||j==r) ps[k++]=bk[(j==r?i:j)++];
        else ps[k++]=bk[(bk[i].x+bk[i].y<=bk[j].x+bk[j].y?i:j)++];
      }
    }
  }

  vector< pair<int, int> > build(){
    vector< pair<int, int> > res;
    int n=xs.size();
    ps.resize(n);bk.resize(n);
    for(int b=0;b<4;b++){
      for(int i=0;i<n;i++){
        if(b&1) swap(xs[i],ys[i]);
        if(b&2) xs[i]*=-1;
        ps[i]=Point(xs[i],ys[i],i);
      }
      sort(ps.begin(),ps.end());
      dfs(0,n);
      for(int i=0;i<n;i++){
        if(b&1) swap(xs[i],ys[i]);
        if(b&2) xs[i]*=-1;
        if(ps[i].idy<0) continue;
        int u=ps[i].idx,v=ps[i].idy;
        if(u>v) swap(u,v);
        res.emplace_back(u,v);
      }
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test

//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif

#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct Kruskal{

  struct edge{
    int from,to;
    T cost;
    int used;
    edge(int from,int to,T cost):
      from(from),to(to),cost(cost),used(0){}
    bool operator<(const edge& e) const{
      return cost<e.cost;
    }
  };
  vector<int> r,p;
  vector<edge> es;

  Kruskal(){}
  Kruskal(int n):r(n,1),p(n){
    iota(p.begin(),p.end(),0);
  }

  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }

  bool same(int x,int y){
    return find(x)==find(y);
  }

  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }

  void add_edge(int u,int v,T c){
    es.emplace_back(u,v,c);
  }

  T build(){
    sort(es.begin(),es.end());
    T res=0;
    for(auto &e:es){
      if(!same(e.from,e.to)){
        res+=e.cost;
        unite(e.from,e.to);
        e.used=1;
      }
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
int main(){
  return 0;
}
#endif

#undef call_from_test

signed main(){
  int n;
  cin>>n;

  vector<int> xs(n),ys(n);
  for(int i=0;i<n;i++)
    cin>>xs[i]>>ys[i];

  ChebyshevNeighbors<int> C(xs,ys);
  auto es=C.build();

  Kruskal<long long> G(n);
  for(auto e:es){
    int u,v;
    tie(u,v)=e;
    int c=max(abs(xs[u]-xs[v]),abs(ys[u]-ys[v]));
    G.add_edge(u,v,c);
  }
  cout<<G.build()<<endl;
  return 0;
}

