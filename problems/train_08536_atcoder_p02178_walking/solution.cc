#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

llint n, c, s, t;
vector<edge> G[100005];
bool path[100005];

bool pdfs(int v, int p)
{
	if(v == t){
		return path[v] = true;
	}
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == p) continue;
		if(pdfs(G[v][i].to, v)) return path[v] = true;
	}
	return false;
}

bool dfs(int v, int p)
{
	vector<int> vec;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == p) continue;
		if(!dfs(G[v][i].to, v)) return false;
		if(path[v] && path[G[v][i].to]){
			if((G[v][i].cost-1) / c < (llint)G[v].size()-1) return false;
		}
		else{
			if(G[v][i].cost - (llint)G[G[v][i].to].size() * c - 1 < 0) vec.push_back(-1);
			else vec.push_back((G[v][i].cost - (llint)G[G[v][i].to].size() * c - 1) / c);
		}
	}
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < vec.size(); i++){
		if(v != s){
			if(vec[i] < i+1) return false;
		}
		else{
			if(vec[i] < i) return false;
		}
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> c >> s >> t;
	llint u, v, w;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v >> w;
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
	}
	if(c == 0){
		cout << "Yes" << endl;
		return 0;
	}
	
	pdfs(s, -1);
	
	/*for(int i = 1; i <= n; i++){
		cout << path[i] << " ";
	}
	cout<< endl;*/
	
	if(dfs(s, -1)) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
