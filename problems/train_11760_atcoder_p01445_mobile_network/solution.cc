#include<iostream>
#include<sstream>
#include<queue>
using namespace std;
const int N = 51;

class E{
public:
  int a[N];
  E(){
    for(int i=0;i<N;i++)a[i]=0;
  }
  E(int n){
    for(int i=0;i<N;i++)a[i]=0;
  }
  E(int n,int val){
    for(int i=0;i<N;i++)a[i]=val;
  }
  E(int n,int v,int s){
    for(int i=0;i<N;i++)a[i]=0;
    a[0]=1;
  }
  E operator+(const E &c)const{
    E ret(N);
    for(int i=0;i<N;i++)ret.a[i]=a[i]+c.a[i];
    return ret;
  }
  E operator-(const E &c)const{
    E ret(N);
    for(int i=0;i<N;i++)ret.a[i]=a[i]-c.a[i];
    return ret;
  }
  E& operator+=(const E &b){
    for(int i=0;i<N;i++)a[i]+=b.a[i];
    return *this;
  }
  E& operator-=(const E &b){
    for(int i=0;i<N;i++)a[i]-=b.a[i];
    return *this;
  }
  bool operator<(const E & b)const{
    for(int i=N-1;i>=0;i--)if (a[i] != b.a[i])return a[i] < b.a[i];
    return false;
  }
  bool operator>(const E &b)const{
    for(int i=N-1;i>=0;i--){
      if (a[i] != b.a[i])return a[i] > b.a[i];
    }
    return false;
  }
  bool operator==(const E &b)const{
    for(int i=0;i<N;i++)if (a[i] != b.a[i])return false;
    return true;
  }
  void op(){
    bool isf=true;
    for(int i=N-1;i>=1;i--){
      if (a[i] == 0)continue;
      if (a[i] > 0){
        if (!isf)cout <<"+";
        if (a[i] > 1)cout << a[i];
      }else {
        if (a[i] == -1)cout <<"-";
        else cout << a[i];
      }
      cout <<"x";
      if (i > 1)cout <<"^"<< i; 
      isf=false;
    }
    if (isf)cout << a[0];
    else if (a[0] != 0){
      if (a[0] > 0)cout <<"+" << a[0];
      if (a[0] < 0)cout << a[0];
    }
    cout << endl;
  }
};

E parse(string &in){
  E ret(N);
  int p=0;
  while(p < (int)in.size()){
    int neg=1;
    int a=0,x=0;
    if (in[p] == '+')p++;
    if (in[p] == '-')neg=-1,p++;
    if (isdigit(in[p])){
      while(p < (int)in.size() && isdigit(in[p]))
        a=a*10+in[p++]-'0';
    }else a=1;
    
    if (in[p] == 'x'){
      p++;
      if (in[p] != '^')x=1;
      else p++;
      while(p < (int)in.size() && isdigit(in[p]))x=x*10+in[p++]-'0';
    }
    ret.a[x]=a;
    ret.a[x]*=neg;
  }
  return ret;
}

const int MAX = 100;
const E ZERO(N);
const E INF(N,(1<<25));
const E ONE(N,1,1);
E cap[MAX][MAX];
bool vis[MAX];
int parent[MAX];
E flow[MAX][MAX];
int layer[MAX]; 

void make_layer(int n,int s,int t){
  queue<int> Q;
  Q.push(s);
  layer[s]=0;
  while(!Q.empty()){
    int now = Q.front();Q.pop();
    for(int i=0;i<n;i++){
      if (cap[now][i]-flow[now][i] > ZERO && layer[i] == -1){
        layer[i] = layer[now]+1;
        Q.push(i);
      }
    }
  }
}

E augment(int now,int t,int n,E f){
  if (now == t || f == ZERO)return f;
  if (vis[now])return ZERO;
  vis[now]=true;
  for(int i=0;i<n;i++){
    if (layer[now] < layer[i]){
      E tmp = augment(i,t,n,min(f,cap[now][i]-flow[now][i]));
      if (tmp > ZERO){
        flow[now][i]+=tmp;
        flow[i][now]=ZERO-flow[now][i];
        vis[now]=false;
        return tmp;
      }      
    }
  }
  return ZERO;
}

void dinic(int n,int s,int t){
  E ansflow=ZERO;
  bool flag=true;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)flow[i][j]=ZERO;
  while(flag){
    fill(layer,layer+n,-1);
    fill(vis,vis+n,false);
    make_layer(n,s,t);
    if (layer[t] == -1)break;
    
    for(E f=ZERO;;flag=true){
      f=augment(s,t,n,INF);
      bool fg=false;
      for(int i=0;i<N;i++)if (f.a[i]!=0)fg=true;
      if (!fg)break;
      ansflow+=f;
    }
  }
  ansflow.op();
}

int main(){
  int n,m;
  while(cin>>n>>m && n){
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        cap[i][j]=ZERO;
    for(int i=0;i<m;i++){
      int f,t;
      string tmp;
      cin>>f>>t>>tmp;
      f--;t--;
      E a=parse(tmp);
      cap[f][t]+=a;
      cap[t][f]+=a;
    }
    dinic(n,0,n-1);
  }
}