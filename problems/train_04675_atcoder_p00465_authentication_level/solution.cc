#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cassert>
using namespace std;

class state{
public:
  int x,y,n;
  state(int y=0, int x=0, int n=0):y(y),x(x),n(n){}
  bool operator < (const state &s) const {return n > s.n;}
};

const int INF = (1<<29);
typedef pair<int,int> P;
int r,h,w,rx,ry,a[500][500],nowl,cntr;//,minl;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
bool f[500][500];
vector<int> numr[2],numl[2];
priority_queue<state> Q;
set<P> s;

bool check(int y, int x){
  if(y < 0 || y >= h) return false;
  if(x < 0 || x >= w) return false;
  return true;
}

void dfs(int y, int x){
  f[y][x] = true;
  cntr++;
  for(int i=0;i<4;i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(check(ny,nx) && !f[ny][nx]){
      if(a[ny][nx] <= nowl) dfs(ny,nx);
      else{
	//minl = min(minl,a[ny][nx]);
	if(s.find(P(ny,nx)) == s.end()){
	    Q.push(state(ny,nx,a[ny][nx]));
	    s.insert(P(ny,nx));
	  }
	  
      }
    }
  }
}

void solve(int k){
  nowl = 1;
  numr[k].clear();
  numl[k].clear();
  s.clear();
  fill(f[0],f[500],false);
  //Q.clear();
  Q.push(state(ry,rx,1));
  cntr = 0;
  while(!Q.empty()){
    state u = Q.top();
    Q.pop();
    nowl = u.n;
    /*
    minl = INF;
    for(int i=0;i<Q.size();i++){
      if(a[][] <= nowl){
	if(!f[Q[i].first][Q[i].second]) dfs(Q[i].first,Q[i].second);
	Q.erase(Q.begin()+i);
	i--;
	}
	}*/
    if(f[u.y][u.x]) continue;
    dfs(u.y,u.x);

    numr[k].push_back(cntr);
    numl[k].push_back(nowl);
    //if(cntr == h * w || cntr >= r) return;
    //nowl = minl;
  }
}

int main(){
  while(cin >> r && r){
    int ans = INF;
    for(int k=0;k<2;k++){
      cin >> w >> h >> rx >> ry;
      rx--;
      ry--;
      for(int i=0;i<h;i++)
	for(int j=0;j<w;j++)
	  cin >> a[i][j];
      solve(k);

      //for(int i=0;i<numr[k].size();i++) cout << numr[k][i] << ' ' << numl[k][i] << endl;
      //cout << endl;

    }
    for(int i=0;i<numr[0].size();i++){
      if(numr[0][i] >= r){
	ans = min(numl[0][i],ans);
	break;
      }
      int cnt = r - numr[0][i];
      int pos = upper_bound(numr[1].begin(), numr[1].end(), cnt) - numr[1].begin();
      if(pos < numr[1].size()) ans = min(ans,numl[0][i] + numl[1][pos]);
      pos = max(0,pos-1);
      if(numr[0][i] + numr[1][pos] >= r) ans = min(ans,numl[0][i] + numl[1][pos]);
    }
    int pos = upper_bound(numr[1].begin(), numr[1].end(), r) - numr[1].begin();
    if(pos < numr[1].size()) ans = min(ans,numl[1][pos]);
    pos = max(0,pos-1);
    if(numr[1][pos] >= r) ans = min(ans,numl[1][pos]);
    cout << ans << endl;
  }
}