#include<iostream>
#include<algorithm>
using namespace std;

const int MAX=101;
const int INF=(1<<21);

int main(){
  int n,m;
  int s,g1,g2;
  int pipe[MAX][MAX];

  while(1){
    cin >> n >> m >> s >> g1 >> g2;

  if(n==0 && m==0 && s==0 && g1==0 && g2==0) break;

  for( int i=0;i<=n;i++ ) {
    for( int j=0;j<=n;j++ ) {
      pipe[i][j]=INF;
    }
    pipe[i][i]=0;
  }

  for( int i=0;i<m;i++ ) {
    int b1,b2,c; 
    cin >> b1 >> b2 >> c;
    pipe[b1][b2]=c;
  }

  for( int i=1;i<=n;i++ ) {
    for( int j=1;j<=n;j++ ) {
      for( int k=1;k<=n;k++ ) {
	pipe[j][k]=min(pipe[j][k],pipe[j][i]+pipe[i][k]);
      }
    }
  }
  int ans=INF;
  for( int i=1;i<=n;i++ ){
    ans=min(ans,pipe[s][i]+pipe[i][g1]+pipe[i][g2]);
  }
  cout << ans << endl;
  }
}