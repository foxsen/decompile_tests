#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

vector<vector<int>> v(11111);
int color[11111];
int used[11111];
int c[5];
vector<pair<pair<int,int>,int>> order;
int n,m,distantColor;

int checkColor(int a){
	REP(i,5)c[i] = 0;
	REP(i,v[a].size()){
		c[color[v[a][i]]] = 1;
	}
	REP(i,4)if(!c[i+1])return i + 1;
	return -1;
}

bool readyDfs(int a,int par){
	REP(i,5)c[i] = 0;
	c[color[a]] = 2;
	REP(i,v[a].size()){
		if(used[v[a][i]] == par){
			c[color[v[a][i]]] = true;
		}
	}
	int cou = 0;
	REP(i,4){
		if(c[i+1])cou++;
	}
	return cou == 3;
}

void dfs(int a,int nowColor, int revColor, int par){
	color[a] = revColor;
	REP(i,v[a].size()){
		if(v[a][i] == par)continue;
		if(color[v[a][i]] == revColor){
			dfs(v[a][i], revColor, nowColor, a);
		}
	}
}

int draw(int a){
	int check = checkColor(a);
	if(check != -1)return check;
	REP(i,v[a].size())used[v[a][i]] = a;
	REP(i,v[a].size()){
		if(color[v[a][i]] == 0)continue;
		readyDfs(v[a][i], a);
		REP(j,4)if(c[j+1] == 0){
			dfs(v[a][i], color[v[a][i]], j + 1, a);
			check = checkColor(a);
			if(check != -1)return check;
		}
	}
	//Not reach
	exit(1);
	return -1;
}

int main(){
	
	cin >> n >> m;
	REP(i,n){
		int a,b;cin >> a >> b;
		order.PB(MP(MP(a,b),i));
	}
	REP(i,m){
		int a,b;cin >> a >> b;
		a--; b--;
		v[a].EB(b);
		v[b].EB(a);
	}
		
	sort(ALL(order));
	REP(i,n)color[order[i].SE] = draw(order[i].SE);
	
	REP(i,n)cout << color[i] << endl;
	
	return 0;
}

