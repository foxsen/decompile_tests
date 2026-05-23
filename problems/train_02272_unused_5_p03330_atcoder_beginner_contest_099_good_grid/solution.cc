#include<iostream>
#include<vector>
#include<limits>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define REP(i,N) FOR(i,0,N)

int N, C;
int D[30][30];
int c[3][500] = {0};

int main() {
  scanf("%d%d", &N, &C);
  
  REP(i,C) REP(j,C) scanf("%d", &D[i][j]);
  
  int buf;
  REP(i,N) REP(j,N) {
    scanf("%d", &buf);
    REP(k,C) c[((i+1)+(j+1))%3][k] += D[buf-1][k];
  }

  int minval = numeric_limits<int>::max();
  REP(i,C) REP(j,C) if(i!=j) REP(k,C) if(i!=k && j!=k) {
    int val = c[0][i] + c[1][j] + c[2][k];
    if (val < minval) minval = val;
  }

  printf("%d\n", minval);
  return 0;
}