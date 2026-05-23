#include <iostream>
using namespace std;

#define SZ 1000
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int main(void){
  int n;
  int d[SZ+1][SZ+1], ans;
  
  cin >> n;
  for (int i=0; i<=SZ; i++){
    for (int j=0; j<=SZ; j++) d[i][j] = 0;
  }
  for (int i=0; i<n; i++){
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    d[x0][y0]++; d[x1][y1]++;
    d[x0][y1]--; d[x1][y0]--;
  }
  // Y-acc
  for (int x=0; x<=SZ; x++){
    for (int y=1; y<=SZ; y++){
      d[x][y] += d[x][y-1];
    }
  }
  // X-acc
  ans = d[0][0];
  for (int y=0; y<=SZ; y++){
    ans = MAX(ans, d[0][y]);
    for (int x=1; x<=SZ; x++){
      d[x][y] += d[x-1][y];
      ans = MAX(ans, d[x][y]);
    }
  }
  cout << ans << endl;    
  return 0;
}
  
  

