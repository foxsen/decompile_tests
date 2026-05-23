#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct Node{
  size_t cnt;
  Node *p,*l,*r;
  Node():cnt(0){p=l=r=nullptr;}
  Node(Node* p):cnt(0),p(p){l=r=nullptr;}
};
  
template<typename T,size_t X>
struct BinaryTrie{
  T acc;
  Node *root;
  Int ptr=0;
  static vector<Node> vs;
  BinaryTrie():acc(0),ptr(0){
    if(vs.empty()) vs.resize(3e6);
    root=emplace(nullptr);
  }
  
  inline Node* emplace(Node* p){
    return &(vs[ptr++]=Node(p));
  }

  inline size_t count(Node* a){
    return a?a->cnt:0;
  }
  
  void add(const T b,size_t k=1){
    const T nb=b^acc;
    Node* a=root;
    for(Int i=X-1;i>=0;i--){
      bool f=(nb>>i)&1;
      if(!f&&!a->l) a->l=emplace(a);
      if( f&&!a->r) a->r=emplace(a);
      a=f?a->r:a->l;
    }
    a->cnt+=k;    
    while((a=a->p)) a->cnt=count(a->l)+count(a->r);    
  }

  inline void update(const T b){acc^=b;}

  size_t order_of_key(const T b){
    Node *a=root;
    size_t res=0;
    for(Int i=X-1;i>=0;i--){      
      Node *l=a->l,*r=a->r;
      if((acc>>i)&1) swap(l,r);
      bool f=(b>>i)&1;
      if(f) res+=count(l); 
      a=f?r:l;
      if(!a) break;
    }
    return res;
  }
};
template<typename T, size_t X>
vector<Node> BinaryTrie<T, X>::vs;

signed main(){
  Int n,k;
  scanf("%lld %lld",&n,&k);
  k=n*(n+1)/2-k;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) scanf("%lld",&a[i]);

  auto calc=
    [&](Int x)->Int{
      Int res=0;
      BinaryTrie<Int, 20> bt;
      bt.add(0);
      for(Int i=0;i<n;i++){
        bt.update(a[i]);
        res+=bt.order_of_key(x);
        bt.add(0);
      }
      return res;
    };
  
  Int l=0,r=1<<20;
  while(l+1<r){
    Int m=(l+r)>>1;
    if(calc(m)<=k) l=m;
    else r=m;
  }

  printf("%lld\n",l);
  return 0;
}
