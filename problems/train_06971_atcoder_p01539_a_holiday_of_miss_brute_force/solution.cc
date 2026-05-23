#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <utility>
#include <queue>
#define inf 1000000000

using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> State;
typedef pair<int, State> QState;

struct edge{
	int to, cost;
	edge(){}
	edge(int a, int b){
		to = a, cost = b;
	}
};

int sx, sy, gx, gy;
int n;
int map[305][305];
int Zero = 150;
int lx, ly;
int dist[305][305][6];

int dx[] = {0, 1, 1, 0, -1, -1, 0}, dy[] = {1, 0, -1, -1, -1, 0, 0};
int dx2[] = {0, 1, 1, 0, -1, -1, 0}, dy2[] = {1, 1, 0, -1, 0, 1, 0};

void dijkstra()
{
	for(int x = -lx; x <= lx; x++){
		for(int y = -ly; y <= ly; y++){
			for(int t = 0; t < 6; t++){
				dist[Zero+x][Zero+y][t] = inf;
			}
		}
	}
	dist[Zero+sx][Zero+sy][0] = 0;
	
	priority_queue<QState, vector<QState>, greater<QState> > Q;
	Q.push(make_pair(0, make_pair(make_pair(sx, sy), 0)));
	
	int x, y, t, d, nd;
	int nx, ny, nt;
	while(Q.size()){
		d = Q.top().first;
		x = Q.top().second.first.first;
		y = Q.top().second.first.second;
		t = Q.top().second.second;
		Q.pop();
		if(dist[Zero+x][Zero+y][t] < d) continue;
		for(int i = 0; i < 7; i++){
			int nx = x, ny = y, nt = (t+1)%6;
			if(abs(x)%2==0) nx += dx[i], ny += dy[i];
			else nx += dx2[i], ny += dy2[i];
			if(abs(nx) > lx || abs(ny) > ly) continue;
			if(map[Zero+nx][Zero+ny]) continue;
			nd = d;
			if(i != abs(x * y * t) % 6) nd++;
			if(dist[Zero+nx][Zero+ny][nt] > nd){
				dist[Zero+nx][Zero+ny][nt] = nd;
				Q.push(make_pair(nd, make_pair(make_pair(nx, ny), nt)));
			}
		}
	}
}


int main(void)
{
	cin >> sx >> sy >> gx >> gy;
	cin >> n;
	int x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		map[Zero+x][Zero+y] = 1;
	}
	cin >> lx >> ly;
	
	dijkstra();
	
	int ans = inf;
	for(int i = 0; i < 6; i++) ans = min(ans, dist[Zero+gx][Zero+gy][i]);
	if(ans >= inf) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}
