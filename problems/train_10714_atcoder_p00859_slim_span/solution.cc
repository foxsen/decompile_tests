#include<iostream>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)
#define MAX 100
#define INFTY (1<<21)
int n, m, G[MAX][MAX], E[MAX*MAX];

int eprim( int base ){
    int d[MAX];
    bool visited[MAX];
    rep(i, n){
	d[i] = INFTY;
	visited[i] = false;
    }
    d[0] = 0;
    int cnt = 0;
    int ans = 0;

    while(1){
	int minv = INFTY;
	int u;
	rep(i, n){
	    if ( !visited[i] && minv > d[i]){
		minv = d[i]; u = i;
	    }
	}
	if ( minv == INFTY ) break;
	if ( u != 0 && ans < minv ) ans = minv;
	cnt++;
	visited[u] = true;

	rep(v, n){
	    if ( visited[v] || G[u][v] == INFTY ) continue;
	    if ( base > G[u][v] ) continue;
	    if ( d[v] > G[u][v] - base ){
		d[v] = G[u][v] - base;
	    }
	}
    }
    if ( cnt != n ) return INFTY;
    return ans;
}

void compute(){
    int minv = INFTY;
    rep(i, m){
	minv = min ( minv, eprim(E[i]) );
    }
    if ( minv == INFTY ) cout << -1 << endl;
    else cout << minv << endl;
}

int main(){
    int s, t, e;
    while( cin >> n >> m ){
	if ( n == 0 && m == 0 ) break;
	rep(i, n) rep(j, n) G[i][j] = INFTY;
	rep(i, m){
	    cin >> s >> t >> e;  s--; t--;
	    G[s][t] = G[t][s] = E[i] = e;
	}
	compute();
    }
}