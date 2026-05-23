#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
typedef complex<D> P;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,const vector<T> &A){ll i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}
template<typename T>vector<T> & cset(vector<T> &A,T e=T()){for(auto &I:A){I=e;} return A;}

//BEGIN CUT HERE
template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  int n,height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){}

  void init(int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    dat.assign(2*n,ti);
    laz.assign(2*n,ei);
  }
  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  inline T reflect(int k){
    return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
  }
  inline void eval(int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    dat[k]=reflect(k);
    laz[k]=ei;
  }
  inline void thrust(int k){
    for(int i=height;i;i--) eval(k>>i);
  }
  inline void recalc(int k){
    while(k>>=1)
      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
  }
  void update(int a,int b,E x){
    thrust(a+=n);
    thrust(b+=n-1);
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
    recalc(a);
    recalc(b);
  }
  void set_val(int a,T x){
    thrust(a+=n);
    dat[a]=x;laz[a]=ei;
    recalc(a);
  }
  T query(int a,int b){
    thrust(a+=n);
    thrust(b+=n-1);
    T vl=ti,vr=ti;
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,reflect(l++));
      if(r&1) vr=f(reflect(--r),vr);
    }
    return f(vl,vr);
  }

  template<typename C>
  int find(int st,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,reflect(k));
      return check(acc)?k-n:-1;
    }
    eval(k);
    int m=(l+r)>>1;
    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);
    if(st<=l&&!check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    int vl=find(st,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(st,check,acc,(k<<1)|1,m,r);
  }
  template<typename C>
  int find(int st,C &check){
    T acc=ti;
    return find(st,check,acc,1,0,n);
  }
};
//END CUT HERE

vector<vector<ll>> edge;
vector<pll> K;

void dfs(ll w,ll p,ll &cnt){
  K[w].F=cnt;
  cnt++;
  for(auto &I:edge[w]){
    if(I==p){continue;}
    dfs(I,w,cnt);
  }
  K[w].S=cnt;
}

const int MAX=10;

typedef vector<int> Data;

int main(){
  ll n,q;
  cin>>n>>q;
  edge.resize(n);
  K.resize(n);
  ll cnt=0;
  for(int i=1;i<n;i++){
    ll u,v;
    cin>>u>>v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(0,-1,cnt);

  Data ti(10,0);
  Data ei(10);
  Data def=ti; def[0]=1;
  for(int i=0;i<MAX;i++){ei[i]=i;}

  auto f=[&](Data a,Data b){
           for(int i=0;i<MAX;i++){
             a[i]+=b[i];
           }
           return a;
  };
  auto g=[&](Data a,Data b){
           Data ret=ti;
           for(int i=0;i<MAX;i++){
             ret[b[i]]+=a[i];
           }
           return ret;
  };
  auto h=[&](Data a,Data b){
           Data ret=ei;
           for(int i=0;i<MAX;i++){
             ret[i]=b[a[i]];
           }
           return ret;
  };

  SegmentTree<Data,Data> T(f,g,h,ti,ei);
  T.build(vector<Data>(cnt,def));

  while(q--){
    ll t,r,x,y;
    cin>>t>>r>>x>>y;
    if(t==1){
      auto ret=T.query(K[r].F,K[r].S);
      ll cnt=0;
      for(int i=0;i<MAX;i++){
        if(x<=i && i<=y){cnt+=ret[i];}
      }
      cout<<cnt<<endl;
    }
    else{
      Data e=ei;
      e[x]=y;
      T.update(K[r].F,K[r].S,e);
    }
  }

  return 0;
}

