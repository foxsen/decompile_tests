#include <cstdio>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#define IN(x,s,g) ((x) >= (s) && (x) < (g))
#define ISIN(x,y,w,h) (IN((x),0,(w)) && IN((y),0,(h)))

using namespace std;

int h, w;
int g[10][10];
int cnt;

const int _dx[] = {0,1,0,-1};
const int _dy[] = {-1,0,1,0};
const char *toS = "URDL";

char ans[50];
int ansp;

void solve(int x, int y, int d){
  if(ansp == cnt){
    ans[ansp] = '\0';
    throw 0;
  }else{
    REP(i,4) if((d - i + 4) % 4 != 2){
      int xx = x + _dx[i];
      int yy = y + _dy[i];

      while(ISIN(xx, yy, w, h)){
        if(g[yy][xx] == 1){
          ans[ansp++] = toS[i];
          g[yy][xx] = 0;
          solve(xx, yy, i);
          g[yy][xx] = 1;
          ansp--;
          break;
        }
        xx += _dx[i];
        yy += _dy[i];
      }
    }
  }
}

int main(){
  int sx, sy;
  int sd;

  scanf("%d%d", &h, &w);

  REP(i,h){
    char buff[20];
    scanf("%s", buff);
    REP(j,w){
      if(buff[j] == '.' || buff[j] == 'o'){
        g[i][j] = (buff[j] == '.' ? 0 : 1);
        if(g[i][j] == 1) cnt++;
      }else{
        g[i][j] = 0;
        sx = j; sy = i;
        switch(buff[j]){
        case 'U': sd = 0; break;
        case 'D': sd = 2; break;
        case 'R': sd = 1; break;
        case 'L': sd = 3; break;
        }
      }
    }
  }

  try{
    solve(sx, sy, sd);
  }catch(int e){
    puts(ans);
  }

  return 0;
}