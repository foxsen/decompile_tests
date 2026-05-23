#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int W, H, N;
int wall[4][50][50];
int step[50][50];
int visit[50][50];

int search(int ix, int iy, int ox, int oy){
	memset(step, -1, sizeof(step));
	step[ix][iy] = 0;
	queue< pair<int,int> > qu; qu.push(make_pair(ix, iy));
	while(!qu.empty()){
		pair<int,int> pr = qu.front(); qu.pop();
		int x = pr.first, y = pr.second;
		for(int i=0;i<4;i++){
			if(wall[i][x][y]) continue;
			int nx = x+dx[i], ny = y+dy[i];
			if(nx<0 || W<=nx || ny<0 || H<=ny) continue;
			if(step[nx][ny]!=-1) continue;
			step[nx][ny] = step[x][y]+1;
			qu.push(make_pair(nx,ny));
		}
	}
	return step[ox][oy];
}

int main(){
	while(cin >> W >> H >> N && W){
		memset(wall, 0, sizeof(wall));
		for(int i=0;i<N;i++){
			int sx, sy, gx, gy;
			cin >> sx >> sy >> gx >> gy;
			if(sx == gx){
				if(0 < sx && sx < W){
					if(sy > gy) swap(sy, gy);
					for(int i=sy;i<gy;i++){
						wall[0][sx-1][i] = wall[2][sx][i] = 1;
					}
				}
			} else {
				if(0 < sy && sy < H){
					if(sx > gx) swap(sx, gx);
					for(int i=sx;i<gx;i++){
						wall[1][i][sy-1] = wall[3][i][sy] = 1;
					}
				}
			}
		}
		int ix, iy, ox, oy;
		cin >> ix >> iy >> ox >> oy;
		int cur = search(ix, iy, ox, oy);
		int best = cur;
		for(int i=0;i<W;i++){
			for(int j=0;j<H;j++){
				if(i+1<W && !wall[0][i][j]){
					wall[0][i][j] = wall[2][i+1][j] = 1;
					best = max(best, search(ix, iy, ox, oy));
					wall[0][i][j] = wall[2][i+1][j] = 0;
				}
				if(j+1<H && !wall[1][i][j]){
					wall[1][i][j] = wall[3][i][j+1] = 1;
					best = max(best, search(ix, iy, ox, oy));
					wall[1][i][j] = wall[3][i][j+1] = 0;
				}
			}
		}
		cout << best-cur << endl;
	}
}