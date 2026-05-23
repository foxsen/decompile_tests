#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
const ll inf=2147483647;
struct segtree{
private:
  ll siz;
  vector<ll> node,lazy;
  vector<bool> lazyflag;
public:
  segtree(ll n){
    siz=1;
    while(siz<=n) siz*=2;
    node.resize(2*siz-1,inf);
    lazy.resize(2*siz-1);
    lazyflag.resize(2*siz-1,false);
  }
  void eval(ll k,ll l,ll r){
    if(lazyflag[k]){
      node[k]=lazy[k];
      if(r-l>1){
        lazy[2*k+1]=lazy[k];
        lazy[2*k+2]=lazy[k];
        lazyflag[2*k+1]=true;
        lazyflag[2*k+2]=true;
      }
      lazyflag[k]=false;
    }
  }
  void update(ll a,ll b,ll x,ll k,ll l,ll r){
    eval(k,l,r);
    if(b<=l||r<=a) return;
    if(a<=l&&r<=b){
      lazy[k]=x;
      lazyflag[k]=true;
      eval(k,l,r);
    }
    else{
      update(a,b,x,2*k+1,l,(l+r)/2);
      update(a,b,x,2*k+2,(l+r)/2,r);
      node[k]=min(node[2*k+1],node[2*k+2]);
    }
  }
  void upd(ll a,ll b,ll x){
    update(a,b,x,0,0,siz);
  }
  ll getmin(ll a,ll b,ll k,ll l,ll r){
    eval(k,l,r);
    if(r<=a||b<=l) return inf;
    if(a<=l&&r<=b) return node[k];
    return min(getmin(a,b,2*k+1,l,(l+r)/2),getmin(a,b,2*k+2,(l+r)/2,r));
  }
  ll min_q(ll a,ll b){
    return getmin(a,b,0,0,siz);
  }
  void debug(){
    for(int i=0;i<node.size();i++) cout<<node[i]<<" ";
    cout<<endl;
    for(int i=0;i<lazy.size();i++) cout<<lazy[i]<<" ";
    cout<<endl;
  }
};
int main(){
  int n,q;
  cin>>n>>q;
  segtree seg=segtree(n+5);
  for(int i=0;i<q;i++){
    int c;
    cin>>c;
    if(c==0){
      ll x,y,z;
      cin>>x>>y>>z;
      seg.upd(x,y+1,z);
    }
    else{
      ll x,y;
      cin>>x>>y;
      cout<<seg.min_q(x,y+1)<<endl;
    }
    //seg.debug();
  }
}

