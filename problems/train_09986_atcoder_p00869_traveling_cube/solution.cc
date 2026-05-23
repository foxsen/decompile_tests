#include<iostream>
#include<queue>
#include<set>

using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define DIRMAX 4

#define DBOTTOM 0
#define DSOUTH 1
#define DWEST 2
#define DNORTH 3
#define DEAST 4
#define DTOP 5
 
const int dc[] = {120,24,6,2,1};
struct Dice{
  int D[6];
  void roll(int dir){
    int tmp;
    switch(dir){
    case NORTH:tmp=D[DNORTH];D[DNORTH]=D[DTOP];D[DTOP]=D[DSOUTH];D[DSOUTH]=D[DBOTTOM];D[DBOTTOM]=tmp;break;
    case EAST: tmp=D[DEAST];D[DEAST]=D[DTOP];D[DTOP]=D[DWEST];D[DWEST]=D[DBOTTOM];D[DBOTTOM]=tmp;break;
    case SOUTH:tmp=D[DSOUTH];D[DSOUTH]=D[DTOP];D[DTOP]=D[DNORTH];D[DNORTH]=D[DBOTTOM];D[DBOTTOM]=tmp;break;
    case WEST: tmp=D[DWEST];D[DWEST]=D[DTOP];D[DTOP]=D[DEAST];D[DEAST]=D[DBOTTOM];D[DBOTTOM]=tmp;break;
    }
  }
  // 54126
  void rot(){
    int tmp=D[DSOUTH];
    D[DSOUTH]=D[DEAST];D[DEAST]=D[DNORTH];D[DNORTH]=D[DWEST];D[DWEST]=tmp;
  }
  int index()const{
    int ret = 0;
    for(int i = 0; i < 5; ++i){
      if(D[i]>D[i+1])ret+=dc[i]*(D[i]-D[i+1]);
    }
    return ret;
  }
  int toint()const{
    int ret = 0;
    for(int i = 0; i < 6; ++i){
      ret *= 10;
      ret += D[i];
    }
    return ret;
  }
  void print()const{
    for(int i = 0; i < 6; ++i){
      cout << D[i] << ' ';
    }
    cout << endl;
  }
};

#define MAX 32

int conv[128];
char rev[16];

struct state{
  Dice d;
  int i,j;
  int step;
  int cost;
  state(Dice td,int i, int j, int step, int cost):i(i),j(j),step(step),cost(cost){d=td;}
  bool operator<(const state &t)const{
    if( i != t.i ) return i < t.i;
    if( j != t.j ) return j < t.j;
    if( step != t.step ) return step < t.step;
    //    if( cost < t.cost ) return cost < t.cost;

    int st = d.toint();
    int tst = t.d.toint();
    if( st != tst ) return st < tst;
    return false;
  }
};

const int infty = 1<<28;
const int di[] = {-1,0,1,0};
const int dj[] = {0,1,0,-1};

bool isinside(int h, int w, int i, int j){
  return 0<=i && i<h && 0<=j && j<w;
}

int solve(int H, int W, char M[MAX][MAX]){
  int ret = infty;
  int si,sj;
  Dice d;
  d.D[DTOP]=conv[(int)'r'];
  d.D[DBOTTOM]=conv[(int)'c'];
  d.D[DNORTH]=conv[(int)'g'];
  d.D[DSOUTH]=conv[(int)'m'];
  d.D[DEAST]=conv[(int)'b'];
  d.D[DWEST]=conv[(int)'y'];

  set<state> vis;

  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      if( M[i][j] == '#' ){
	si = i;
	sj = j;
      }
    }
  }
  
  state init(d,si,sj,1,0);
  queue< state > q;
  q.push( init );

  vis.insert(init);
  while(!q.empty()){
    state nst = q.front(); q.pop();
    Dice nd = nst.d;
    if(nst.step == 7){
      ret = min(ret,nst.cost);
    }else{
      for(int kk = 0; kk < 4; ++kk){
	int nexti = nst.i + di[kk];
	int nextj = nst.j + dj[kk];
	if( isinside( H, W, nexti, nextj ) ){
	  if( M[nexti][nextj] == 'k' ) continue;
	  Dice tmp = nd;
	  nd.roll(kk);
	  //	  cout << nexti << ' ' << nextj << ' ' << nd.D[DTOP] << ' ' << rev[nd.D[DTOP]] << ' ' << M[nexti][nextj] << endl;
	  bool gain_step = (rev[nd.D[DTOP]] == M[nexti][nextj]) && (nst.step == conv[(int)M[nexti][nextj]]);
	  if( gain_step || M[nexti][nextj] == 'w' || M[nexti][nextj] == '#' ){
	    state next_state(nd, nexti,nextj,nst.step+(gain_step?1:0),nst.cost+1);
	    // cout << nd.index() << ' ' << next_state.step << ' ' << nexti << ' ' << nextj << endl;
	    if( vis.find(next_state) == vis.end() ){
	      vis.insert( next_state );
	      q.push( next_state );
	    }
	  }
	  nd = tmp;
	}
      }
    }
  }
  return ret;
}

int main()
{
  int w,d;
  while(cin >> w >> d){
    if( w == 0 && d == 0 ){
      break;
    }

    char M[MAX][MAX];
    for(int i = 0; i < d; ++i){
      for(int j = 0; j < w; ++j){
	cin >> M[i][j];
      }
    }
    
    for(int i = 0; i < (int)(sizeof(conv)/sizeof(*conv)); ++i){ conv[i] = -1; }
    for(int i = 0; i < (int)(sizeof(rev)/sizeof(*rev)); ++i){ rev[i] = 0; }

    for(int i = 0; i < 6; ++i){
      char c; cin >> c;
      conv[(int)c] = 1+i;
      rev[1+i] = c;
      //cout << c << endl;
    }
    int res = solve(d,w,M);
    if(res>=infty){
      cout <<"unreachable"<<endl;
    }else{
      cout << solve( d, w, M ) << endl;
    }
  }
  return 0;
}