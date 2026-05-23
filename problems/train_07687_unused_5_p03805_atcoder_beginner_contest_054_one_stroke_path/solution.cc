#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
bool used[9],d[9][9];
void dfs(int p, int c){
  if(c==n) ans++;
  used[p]=1;
  for(int i=1; i<=n; i++){
  	if(!used[i] && d[p][i]) dfs(i, c+1);
  }
  used[p]=0;
}
  int main(){
    cin >> n >> m;
    for(int i=0,a,b; i<m; i++){
    	cin >> a >> b;
      d[a][b]=d[b][a]=1;
    }
	dfs(1,1);
    cout << ans << endl;
}