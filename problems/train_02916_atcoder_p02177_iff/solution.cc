#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> G[305], revG[305];
vector<int> topo;
bool used[305];
int scc[305];

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) tpsort(G[v][i]);
	}
	topo.push_back(v);
}
void sccdfs(int v, int id)
{
	used[v] = true;
	scc[v] = id;
	for(int i = 0; i < revG[v].size(); i++){
		if(!used[revG[v][i]]) sccdfs(revG[v][i], id);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		revG[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++) if(!used[i]) tpsort(i);
	reverse(topo.begin(), topo.end());
	
	int id = 0;
	for(int i = 1; i <= n; i++) used[i] = false;
	for(int i = 0; i < topo.size(); i++) if(!used[topo[i]]) sccdfs(topo[i], id++);
	
	for(int i = 1; i <= n; i++){
		vector<int> vec;
		for(int j = 1; j <= n; j++){
			if(scc[i] == scc[j]){
				vec.push_back(j);
			}
		}
		for(int j = 0; j < vec.size(); j++){
			cout << vec[j];
			if(j < (int)vec.size()-1) cout << " ";
		}
		cout << endl;
	}
	
	return 0;
}
