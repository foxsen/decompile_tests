#include<bits/stdc++.h>
using namespace std;
#define INF 1000000007
typedef pair<int, int> P;
vector<P> sg;
vector<P> edge[1501];
int leng[1501][1501], f[1501][1501], flg[1501];
vector<int> fl;
int main(void){
	int n, r;
	cin >> n >> r;
//	cout << n << endl;
	for(int i = 0; i < r; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back(P(b, c)); edge[b].push_back(P(a, c));
	}
	fill(leng[0], leng[n + 1], INF);
	int mx = -1;
	for(int i = 1; i <= n; i++){
		leng[i][i] = 0;
		priority_queue<P, vector<P>, greater<P> > que;
		que.push(P(0, i));
		while(!que.empty()){
			P p = que.top(); que.pop();
			int cost = p.first, from = p.second;
			if(leng[i][from] < cost) continue;
			for(int j = 0; j < edge[from].size(); j++){
				int to = edge[from][j].first, cost = edge[from][j].second;
				if(leng[i][to] > leng[i][from] + cost){
					leng[i][to] = leng[i][from] + cost;
					que.push(P(leng[i][to], to));
				}
			}
		}
		for(int j = 1; j <= n; j++) if(leng[i][j] != INF) mx = max(mx, leng[i][j]);
	}
/*	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) cout << leng[i][j] << ' ';
		cout << endl;
	}*/
	fill(f[0], f[n + 1], 1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(f[i][j]){
				if(leng[i][j] == mx){
					sg.push_back(P(i, j));
					f[i][j] = 0; f[j][i] = 0;
				}
			}
		}
	}
//	cout << sg.size() << endl;
	fill(flg, flg + n + 1, 1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) if(!f[i][j]) flg[i] = 0, flg[j] = 0;			
	}
	for(int i = 1; i <= n; i++) if(flg[i]) fl.push_back(i);
//	cout << "コアダンブ" << endl;
	for(int i = 0; i < sg.size(); i++){
		int start = sg[i].first, goal = sg[i].second;
		for(int j = 0; j < fl.size(); j++){
			int via = fl[j];
			if(leng[start][via] + leng[via][goal] == mx) flg[via] = 0;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) if(flg[i]) cnt++;
	cout << cnt << endl;
	for(int i = 1; i <= n; i++) if(flg[i]) cout << i << endl;
	return 0;
}
