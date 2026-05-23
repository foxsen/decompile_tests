#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);(i)++)
#define rep(i,n) repl(i,0,n)
#define dbg(x) cout<<#x<<"="<<x<<endl

#define INF INT_MAX/3

struct RangeMinQuery{
  int dat[(1<<19)-1];
  int size;

  void init(int n_){
    size=1;
    while(size<n_)size*=2;
    for(int i=0;i<2*size-1;i++)dat[i]=INF;
  }

  void update(int k,int a){
    k+=size-1;
    dat[k]=a;
    while(k>0){
      k=(k-1)/2;
      dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
  }

  int subquery(int a,int b,int k,int l,int r){
    if(r<=a||b<=l)return INF;
    if(a<=l&&r<=b)return dat[k];
    else{
      return min(subquery(a,b,k*2+1,l,(l+r)/2),subquery(a,b,k*2+2,(l+r)/2,r));
    }
  }

  int query(int a,int b){
    return subquery(a,b,0,0,size);
  }
};

struct BIT{
  int n;
  vector<int> bit;
  BIT(int size):n(size),bit(size+1,0){}

  int sum(int i){
    int s=0;
    while(i>0){
      s+=bit[i];
      i-=i&-i;
    }
    return s;
  }

  void add(int i,int v){
    if(i==0)return ;
    while(i<=n){
      bit[i]+=v;
      i+=i&-i;
    }
  }

  int lower_bound(int w){
    if(w<=0)return 0;
    int x=0,r=1;
    while(r<n)r<<=1;
    for(int k=r;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<w){
        w-=bit[x+k];
        x+=k;
      }
    }
    return x+1;
  }
};

int N,Q;
char input[1000010];
vector<string> S;
vector<int> ord;
int ridx[100010],lcp[100010];
RangeMinQuery rmq;

int main(){
  scanf("%d",&N);
  S.resize(N);
  rep(i,N){
    scanf("%s",input);
    S[i]=string(input);
    ord.push_back(i);
  }
  sort(ord.begin(),ord.end(),[=](const int& a,const int& b){
    return S[a] < S[b];
  });
  rep(i,N){
    ridx[ord[i]]=i;
  }
  rmq.init(N-1);
  rep(i,N-1){
    lcp[i]=0;
    rep(j,min(S[ord[i]].size(),S[ord[i+1]].size())){
      if(S[ord[i]][j]==S[ord[i+1]][j])lcp[i]++;
      else break;
    }
    // dbg(lcp[i]);
    rmq.update(i,lcp[i]);
  }

  BIT bit(N);

  scanf("%d",&Q);
  rep(i,Q){
    int a,b;
    scanf("%d%d",&a,&b);
    a--; b--;
    if(a==0){
      bit.add(ridx[b]+1,+1);
    }else if(a==1){
      bit.add(ridx[b]+1,-1);
    }else{
      int sum=bit.sum(ridx[b]);
      int idx=bit.lower_bound(sum+1);
      if(idx==N+1){
        cout<<-1<<endl;
        continue;
      }
      int len=rmq.query(ridx[b],idx-1);
      if(len>=(int)S[b].size())cout<<ord[idx-1]+1<<endl;
      else cout<<-1<<endl;
    }
  }

  return 0;
}

