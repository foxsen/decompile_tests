#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int N;
vector <int> tree[2010];

int X;
int L[2010][2010],R[2010][2010],order[2010][2010]; // root, node -> rank
set <int> s[2010];

void pre_dfs(int r, int p, int x){
	L[r][x] = X;
	order[r][X] = x;
	X++;
	
	int i;
	REP(i,tree[x].size()){
		int y = tree[x][i];
		if(y != p) pre_dfs(r, x, y);
	}
	
	R[r][x] = X;
}

bool is_child(int r, int x, int y){ // is y grandchildren of x?
	return (L[r][y] >= L[r][x] && R[r][y] <= R[r][x]);
}

bool exist(int x, int y){
	return (s[x].find(L[x][y]) != s[x].end());
}

int find_parent(int x, int y){
	__typeof(s[x].begin()) itr = s[x].lower_bound(L[x][y]);
	if(itr == s[x].begin()) return -1;
	itr--;
	return order[x][(*itr)];
}

vector <int> find_children(int x, int y){
	vector <int> ans;
	__typeof(s[x].begin()) itr = s[x].lower_bound(L[x][y]);
	
	while(itr != s[x].end()){
		int z = order[x][(*itr)];
		if(!is_child(x, y, z)) break;
		ans.push_back(z);
		itr++;
	}
	
	return ans;
}

void erase(int x, int y){
	s[x].erase(L[x][y]);
	s[y].erase(L[y][x]);
}

void add_direct(int x, int y){
	s[x].insert(L[x][y]);
	s[y].insert(L[y][x]);
}

void add(int s, int t){
	int i;
	
	if(s == t) return;
	
	if(exist(s, t)) return;
	
	{
		int u = find_parent(s, t);
		if(u != -1 && is_child(s, u, t)){
			add(u, t);
			return;
		}
	}
	
	swap(s, t);
	
	{
		int u = find_parent(s, t);
		if(u != -1 && is_child(s, u, t)){
			add(u, t);
			return;
		}
	}
	
	vector <int> v = find_children(s, t);
	vector <int> w = find_children(t, s);
	
	add_direct(s, t);
	
	REP(i,v.size()){
		int u = v[i];
		erase(s, u);
	}
	
	REP(i,w.size()){
		int u = w[i];
		erase(t, u);
	}
	
	REP(i,v.size()){
		int u = v[i];
		add(t, u);
	}
	
	REP(i,w.size()){
		int u = w[i];
		add(s, u);
	}
}

vector <int> graph[2010];
bool used[2010];

void dfs(int r, int x){
	int i;
	
	if(used[x]) return;
	used[x] = true;
	
	REP(i,graph[x].size()){
		int y = graph[x][i];
		if(is_child(r, x, y)) dfs(x, y);
	}
}

int main(void){
	int M,i,j,ss,t;
	
	cin >> N >> M;
	REP(i,N-1){
		cin >> ss >> t;
		ss--; t--;
		tree[ss].push_back(t);
		tree[t].push_back(ss);
	}
	
	REP(i,N){
		X = 0;
		pre_dfs(i, -1, i);
	}
	
	REP(i,M){
		cin >> ss >> t;
		ss--; t--;
		add(ss, t);
	}
	
	REP(i,N) REP(j,N) if(s[i].find(L[i][j]) != s[i].end()) graph[i].push_back(j);
	
	int ans = 0;
	REP(i,N){
		REP(j,N) used[j] = false;
		dfs(i, i);
		REP(j,N) if(j != i && used[j]) ans++;
	}
	
	cout << ans / 2 << endl;
	
	return 0;
}
