#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(void){
  int h,w,i,j,k,l,ans=0;
  int di[4]={1,0,-1,0},dj[4]={0,1,0,-1};
  string g[23];
  
  cin >> h >> w;
  for (i=0;i<h;i++) cin >> g[i];
  
  for (i=0;i<h;i++) for (j=0;j<w;j++){
    if (g[i][j]=='#') continue;
    int d[23][23]={},ni,nj;
    P p;
    queue<P> q;
    q.push(P(i,j));
    d[i][j]=1;
    while (q.size()>0){
      p=q.front();
      q.pop();
      for (k=0;k<4;k++){
        ni=p.first+di[k];
        nj=p.second+dj[k];
        if (ni>=0 && ni<h && nj>=0 && nj<w && g[ni][nj]=='.' && d[ni][nj]==0){
          q.push(P(ni,nj));
          d[ni][nj]=d[p.first][p.second]+1;
        }
      }
    }
    
    int dmax=0;
    for (k=0;k<h;k++) for (l=0;l<w;l++){
      if (g[k][l]=='.' && dmax<d[k][l]){
        dmax=d[k][l];
      }
    }
    
    ans=max(ans,dmax-1);
    
  }
  
  cout << ans << endl;
  
  return 0;
}