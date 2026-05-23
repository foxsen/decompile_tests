#include <bits/stdc++.h>
#define INF 1000000000
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
	int d[200][200], r[8];
	int N, M, R; cin >> N >> M >> R;
	for(int i = 0; i < R; i++){
		int rr;
		cin >> rr;
		r[i] = --rr;
	}
	fill(d[0], d[N], INF);
	for(int i = 0; i < N; i++) d[i][i] = 0;
	for(int i = 0; i < M; i++){
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		d[a][b] = d[b][a] = c;
	}

	for(int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int res = INF;
	sort(r, r+R);
	do{
		int dist = 0;
		for(int i = 0; i < R - 1; i++) dist += d[r[i]][r[i+1]];
		res = min(res, dist);
	}while(next_permutation(r, r+R));

	cout << res << '\n';

	return 0;
}
