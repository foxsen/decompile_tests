#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define _3_ 1

using namespace std;

/*
  15:25 - 
  ?????????????????????????????????
  ??????????????????
  ??£??????
  ????????????????????¢????¨????
  ?????¨?????????????????????????°???????????????????????¶?????????????
  ---
  
  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?
  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?
  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?
  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?
  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?
  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?
  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?
  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?  _3_ < DO YOU HAVE THE TIME?
  _3_ IT'S A QUATER TO TEN >
  _3_ !!
  
*/

typedef unsigned long long ull;
typedef pair<int,int> ii;

struct Point { int x,y; };

const int IINF = INT_MAX;
const char PATH = '$';

int h,w,s_size,c_size,bitIndex[12][12];
char c[12][12];
Point source[12],city[12],path[12];
int limit,next_limit;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int mini;
int bc[1<<9];
int mani[12];

int initial_heuristic(){
  int sum = 0;
  rep(i,c_size) {
    mani[i] = IINF;
    rep(j,s_size) mani[i] = min(mani[i],abs(city[i].x-source[j].x)+abs(city[i].y-source[j].y));
    rep(j,c_size) if( j != i ) mani[i] = min(mani[i],abs(city[i].x-city[j].x)+abs(city[i].y-city[j].y));
     sum += mani[i];
  }
  return sum;
}


int get_heuristic(int sp,int bitmask){
  int sum = 0;
  rep(i,c_size) if( !( (bitmask>>i) & 1 ) ) {
    mani[i] = min(mani[i],abs(path[sp].x-city[i].x)+abs(path[sp].y-city[i].y));
    sum += mani[i];
  }
  return sum;
}


//typedef pair<ull,int> ullInt;
//map<ullInt,int> mincost; 
//unordered_map<ull,int> mincost; 
//map<ull,int> mincost; 
bool head[12][12];
bool opt[12][12];

int blocks;

void print_field(){
  rep(i,h) {
    rep(j,w){
      cout << c[i][j];
    } puts("");
  }
}

void dfs(int sp,int bitmask,int prev,int step,int depth){

  /*
  cout << "sp = " << sp << " step = " << step << endl;
  print_field(); puts("");
  */
  if( step+(c_size-bc[bitmask]) >= mini ) return;
  
  if( sp >= s_size ) return;

  if( bitmask == ((1<<c_size)-1) ) { 
    //print_field(); puts(""); 
    mini = step; return; }

  //int h = get_heuristic(sp,bitmask);
  //if( step+h >= mini ) return;

  bool next = 1;
  rep(dir,4){
    if( prev != -1 && ( prev + 2 ) % 4 == dir ) continue;
    int nx = path[sp].x + dx[dir], ny = path[sp].y + dy[dir];

    if( c[ny][nx] == 'P' || c[ny][nx] == '#' || c[ny][nx] == PATH ) continue;

    bool success = true;
    int cnt = 0;
    rep(i,4){
      int nx2 = nx + dx[i], ny2 = ny + dy[i];
      if( c[ny2][nx2] == PATH || c[ny2][nx2] == 'P' ) ++cnt;
    }
    if( cnt != 1 ) success = false;
    if( !success ) continue;
    
    Point pp = path[sp];
    char pc = c[ny][nx];
    int nbitmask = bitmask;
    bool fin = false;
    char prec = c[ny][nx];
    if( c[ny][nx] == '*' ) nbitmask |= (1<<bitIndex[ny][nx]), fin = true;

    path[sp] = (Point){nx,ny};
    c[ny][nx] = PATH;
    //short mini_temp[8];
    //rep(i,c_size) mini_temp[i] = mani[i];
    swap(head[path[sp].y][path[sp].x],head[ny][nx]);

    next = 0;
   
    dfs(sp,nbitmask,dir,step+1,depth+1);
    if( prec == '*' )dfs(sp+1,nbitmask,-1,step+1,0);

    //rep(i,c_size) mani[i] = mini_temp[i];
    swap(head[path[sp].y][path[sp].x],head[ny][nx]);
    path[sp] = pp;
    c[ny][nx] = pc;

    //if( c_size-(int)__builtin_popcount(bitmask) == 1 ) return false;
    if( fin ) return;
  }
  //if( c[path[sp].y][path[sp].x] == '*' || current_step == 0 ) dfs(sp+1,bitmask,-1,step,0);  
  //dfs(sp+1,bitmask,-1,step);  
  if( depth == 0 || c[path[sp].y][path[sp].x] == 'P' || c[path[sp].y][path[sp].x] == '*' )  dfs(sp+1,bitmask,-1,step,0);  
} 

int compute(){
  //initial_heuristic();
  mini = h*w-s_size - blocks;
  int csv = 0;
  dfs(0,0,-1,0,0);
  return mini;
}



int main(){
  srand((unsigned int)time(NULL));
  rep(i,(1<<9)) bc[i] = __builtin_popcount(i);
  while( scanf(" %d %d",&h,&w), h|w ){
    s_size = c_size = 0;
    blocks = 0;
    rep(i,h) rep(j,w) {
      head[i][j] = false;
      scanf(" %c",&c[i][j]);
      if( c[i][j] == 'P' ) { source[s_size] = path[s_size] = (Point){j,i}; s_size++; head[i][j] = true; }
      if( c[i][j] == '*' ) { city[c_size]   = (Point){j,i}; bitIndex[i][j] = c_size++; }
      if( c[i][j] == '#' ) ++blocks;
    }
    printf("%d\n",compute());
    //print_field(); puts("");
  }
  return 0;
}