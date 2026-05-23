#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

const char EMPTY = 'X';
 
struct Node{
  short value;
  /*
    lazy : 
    A : 加算の遅延 ( ADD )
    S : 区間の要素を指定した値にする遅延 ( SET )

    lazy_coef : 
    区間にいくら加算するのかor何をセットするのかを記録
   */
  char lazy;
  short lazy_coef; 
  Node(short value=0,char lazy=EMPTY,short lazy_coef=0):value(value),lazy(lazy),lazy_coef(lazy_coef){}
};
 
class SegTree{
public:
  vector<Node> RMQ;
  int limit,N; // N は要素数
 
  void init(int tmp){
    N = tmp;
    int N_N = 1;
    while(N_N < N)N_N *= 2;
    limit = N_N;
    RMQ.clear();
    RMQ.resize(2.3*limit);
    rep(i,2.3*limit-1) RMQ[i] = Node();
  }

  /* 
  O(n)でRMQを初期化
  [L,R)
  tuple<int,int,int>(総和、最小値、最大値)
  */
  short _build(int cur,int L,int R){
    if( !( 0 <= cur && cur < 2*limit-1 ) ) return 0;
    if( L == R-1 ){
      if( L >= N ) return 0;
      //各要素の値が一定でない場合 ( 配列に初期値をいれてそれで初期化する場合 )
      //buf[] を用意し値を入れ RMQ[cur].value = buf[L]; とする
      // RMQのL番目の要素をbuf[L]で更新
      //RMQ[cur].value = buf[L];

      //各要素が全て同じの場合
      RMQ[cur] = 0; // RMQ の各要素を０で初期化、 1 なら RMQ[cur] = 1などなど...
      //minimum_dat[cur] = 0;
      //maximum_dat[cur] = 0;
    } else {
      short vl = _build(cur*2+1,L,(L+R)/2);
      short vr = _build(cur*2+2,(L+R)/2,R);
      RMQ[cur].value = vl+vr;
    }
    return RMQ[cur].value;
  }

  //initしてから使用すること!!! でないとlimitに正しい値が入っていません
  void build() { _build(0,0,limit); }

  inline void value_evaluate(int index,int L,int R){
    if( RMQ[index].lazy == 'A' ){
      RMQ[index].value += ( R - L ) * RMQ[index].lazy_coef;
    } else if( RMQ[index].lazy == 'S' ){
      RMQ[index].value = ( R - L ) * RMQ[index].lazy_coef;
    }
  }
   
  inline void lazy_evaluate(int index,int L,int R){
    value_evaluate(index,L,R);
    if( index < limit && RMQ[index].lazy != EMPTY ) {
      if( RMQ[index].lazy == 'A' ) {
        if( RMQ[index*2+1].lazy == EMPTY ) RMQ[index*2+1].lazy = 'A'; 
        if( RMQ[index*2+2].lazy == EMPTY ) RMQ[index*2+2].lazy = 'A';
        RMQ[index*2+1].lazy_coef += RMQ[index].lazy_coef;
        RMQ[index*2+2].lazy_coef += RMQ[index].lazy_coef;
      } else if( RMQ[index].lazy == 'S') {
        RMQ[index*2+1].lazy = RMQ[index*2+2].lazy = 'S';
        RMQ[index*2+1].lazy_coef = RMQ[index].lazy_coef;
        RMQ[index*2+2].lazy_coef = RMQ[index].lazy_coef;
      }
    }
    RMQ[index].lazy = EMPTY;
    RMQ[index].lazy_coef = 0;
  }
 
  inline void value_update(int index){ RMQ[index].value = RMQ[index*2+1].value + RMQ[index*2+2].value; }

  void _update(int a,int b,char opr,int v,int index,int L,int R){
    lazy_evaluate(index,L,R);
    if( b <= L || R <= a )return;
    if( a <= L && R <= b ){
      RMQ[index].lazy = opr; // 今いるノードに遅延を設定して処理をしてもらう
      if( opr == 'A' )      RMQ[index].lazy_coef += v; 
      else if( opr == 'S' ) RMQ[index].lazy_coef = v; 
      lazy_evaluate(index,L,R);
      return;
    }
    _update(a,b,opr,v,index*2+1,L,(L+R)/2);
    _update(a,b,opr,v,index*2+2,(L+R)/2,R);
    value_update(index);
  }

  void update(int a,int b,char opr,short v){ _update(a,b,opr,v,0,0,limit); } 

  int _query(int a,int b,int index,int L,int R){
    lazy_evaluate(index,L,R); 
    if( b <= L || R <= a ) return 0;
    if( a <= L && R <= b ) return RMQ[index].value;
    short tmp1 = _query(a,b,index*2+1,L,(L+R)/2);
    short tmp2 = _query(a,b,index*2+2,(L+R)/2,R);
    short ret = tmp1+tmp2;
    value_update(index); //ここまでくると子の値が正しくなっているのでその和をとって今いるノードにも正しい値をいれる
    return ret;
  }

  // [a,b) の総和、最小値、最大値を返す
  short query(int a,int b) { return _query(a,b,0,0,limit); }

};

typedef pair<int,int> ii;
const int MAX_V = 1001;
struct Edge {
  int src,dst,depart,arrive;
};

int S,T,D,timeD,Rendezvous,timeRendezvous;

inline int toMinute(string s) { 
  int ret = ( s[3] - '0' ) * 10 + ( s[4] - '0' );
  return ret + ( ( s[0] - '0' ) * 10 + ( s[1] - '0' ) ) * 60;
}

struct Data {
  int cur,time;
  bool operator < ( const Data &data ) const { 
    if( time != data.time ) return time > data.time;
    return cur > data.cur;
  }
};

const int MAX_T = 1441;
vector<Edge> G[MAX_V],rG[MAX_V];
SegTree dp[MAX_V][2]; // dp[station][ 0 : from dept, 1 : to rendezvous] := reachable?
vector<vector<bool> > used;

void compute(vector<int> &N,vector<vector<ii> > &KT){
  rep(i,S) rep(j,2) {
    dp[i][j].init(MAX_T);
    dp[i][j].build();
  }
  
  // dept to other station
  used.clear();
  used.resize(S,vector<bool>(MAX_T,false));
  dp[D][0].update(timeD,MAX_T,'S',1);
  used[D][timeD] = true;
  priority_queue<Data> Q;
  Q.push((Data){D,timeD});
  while( !Q.empty() ){
    Data data = Q.top(); Q.pop();
    rep(i,(int)G[data.cur].size()){
      if( data.time > G[data.cur][i].depart ) continue;
      int next = G[data.cur][i].dst;
      int arrive = G[data.cur][i].arrive;
      if( !used[next][arrive] ) {
        used[next][arrive] = true;
        dp[next][0].update(arrive,1500,'S',1);
        Q.push((Data){next,arrive});
      }
    }
  }

  // each station to ランデヴー
  rep(i,used.size()) rep(j,used[i].size()) used[i][j] = false;
  dp[Rendezvous][1].update(0,timeRendezvous+1,'S',1);
  used[Rendezvous][timeRendezvous] = true;
  assert( Q.empty() );
  Q.push((Data){Rendezvous,timeRendezvous});
  while( !Q.empty() ){
    Data data = Q.top(); Q.pop();
    rep(i,(int)rG[data.cur].size()){
      if( data.time < rG[data.cur][i].depart ) continue;
      int prev = rG[data.cur][i].dst;
      int r_arrive = rG[data.cur][i].arrive;
      if( !used[prev][r_arrive] ){
        used[prev][r_arrive] = true;
        dp[prev][1].update(0,r_arrive+1,'S',1);
        Q.push((Data){prev,r_arrive});
      }
    }
  }
  int maxi = -1;
  rep(i,N.size()){
    rep(j,N[i]-1) {
      int f = KT[i][j].first, ft = KT[i][j].second;
      if( !dp[f][0].query(ft,ft+1) ) continue;
      REP(k,j+1,N[i]){
        int t = KT[i][k].first, tt = KT[i][k].second;
        int sleep = tt - ft;
        assert( sleep >= 1 );
        if( sleep <= maxi ) continue;
        if( dp[t][1].query(tt,tt+1) ) {
          maxi = max(maxi,sleep);
        }
      }
    }
  }
  
  if( maxi == -1 && D == Rendezvous && timeD <= timeRendezvous ) puts("0");
  else if( maxi == -1 ) puts("impossible");
  else printf("%d\n",maxi);
}


int main(){
  while( scanf("%d %d",&S,&T), S|T ){
    rep(i,S) G[i].clear(), rG[i].clear();
    rep(i,MAX_V) rep(j,2) dp[i][j].RMQ.clear();
    string temp;
    cin >> D >> temp;
    --D;
    timeD = toMinute(temp);
    cin >> Rendezvous >> temp;
    --Rendezvous;
    timeRendezvous = toMinute(temp);
    vector<int> N(T);
    vector<vector<ii> > KT(T,vector<ii>());
    rep(i,T){
      cin >> N[i];
      KT[i].resize(N[i]);
      rep(j,N[i]) {
        cin >> KT[i][j].first >> temp;
        --KT[i][j].first;
        KT[i][j].second = toMinute(temp);
      }
      rep(j,N[i]-1) {
        int f = KT[i][j].first  , ft = KT[i][j].second;
        int t = KT[i][j+1].first, tt = KT[i][j+1].second;
         G[f].push_back((Edge){f,t,ft,tt});
        rG[t].push_back((Edge){t,f,tt,ft});
      }
    }

    compute(N,KT);
    
  }
  return 0;
}