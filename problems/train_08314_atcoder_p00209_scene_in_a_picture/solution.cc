#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>
#include<numeric>
#include<cassert>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define rep(i,s,n) for(int i=(s); i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define IN(x,s,g) ((x) >= (s) && (x) < (g))
#define ISIN(x,y,w,h) (IN((x),0,(w)) && IN((y),0,(h)))
#define print(x) printf("%d\n",x)

using namespace std;

typedef unsigned int uint;
typedef long long ll;

const int _dx[] = {0,1,0,-1};
const int _dy[] = {-1,0,1,0};

int getInt(){
  int ret = 0,c;
  c = getchar();
  while(!isdigit(c)) c = getchar();
  while(isdigit(c)){
    ret *= 10;
    ret += c - '0';
    c = getchar();
  }
  return ret;
}

int b[100][100];

int p[4][50][50];

template<int N>
void rotate_cpy(int (*org)[N], int (*dist)[N], int n){
  REP(i,n) REP(j,n)
    dist[n-j-1][i] = org[i][j];
}


int main(){
  int n, m;

  while(scanf("%d%d",&n,&m), n+m){
    int ax = INT_MAX;
    int ay = INT_MAX;

    REP(i,n) REP(j,n) scanf("%d",&b[i][j]);
    REP(i,m) REP(j,m) scanf("%d",&p[0][i][j]);
    REP(i,3) rotate_cpy(p[i], p[i+1], m);

    REP(i,n-m+1) REP(j,n-m+1){
      bool ok[4] = { true, true, true, true };
      int xx[4] = { -1, -1, -1, -1 };
      int yy[4] = { -1, -1, -1, -1 };

      REP(c,4) REP(y,m) REP(x,m) if(ok[c]){
	if(p[c][y][x] == -1) continue;
	if(p[c][y][x] == b[i+y][j+x]){
	  if(xx[c] == -1){
	    xx[c] = j + x;
	    yy[c] = i + y;
	  }
	}else{
	  ok[c] = false;
	}
      }

      if(ok[0] || ok[1] || ok[2] || ok[3]){
	REP(c,4) if(ok[c]){
	  if(ay > yy[c]){
	    ay = yy[c];
	    ax = xx[c];
	  }else if(ay == yy[c] && ax > xx[c]){
	    ay = yy[c];
	    ax = xx[c];
	  }
	}
      }
    }

    if(ax == INT_MAX)
      puts("NA");
    else
      printf("%d %d\n",ax+1,ay+1);
  }

  return 0;
}