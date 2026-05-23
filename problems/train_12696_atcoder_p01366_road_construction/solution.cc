#include <iostream>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;
#define MAX_V 10240
 
// 从顶点from指向顶点to的权值为cost的边
typedef struct edge
{
	int to, distance, cost;
	edge(){}
	edge(int to, int distance, int cost) : to(to), distance(distance), cost(cost){}
	bool operator > (const edge & b) const
	{
		return distance != b.distance ? distance > b.distance : cost > b.cost;
	}
} P;
 
// first 最短路径，second顶点编号
 
// 图
vector<edge> G[MAX_V];
 
// V是顶点数
int V;
bool visited[MAX_V];
 
// 求解从顶点s出发到所有点的最短花费
int dijkstra(int s)
{
	int result = 0;
	priority_queue<P, vector<P>, greater<P> > que;
	memset(visited, 0, V * sizeof(bool));
	que.push(P(0, 0, 0));
 
	while (!que.empty())
	{
		P p = que.top(); que.pop();
		int v = p.to;
		if (visited[v]) continue;
		visited[v] = true;
		result += p.cost;
		for (int i = 0; i < G[v].size(); ++i)
		{
			edge e = G[v][i];
			que.push(P(G[v][i].to, p.distance + G[v][i].distance, G[v][i].cost));
		}
	}
 
	return result;
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
	int /*N = V,*/ M;
	while (cin >> V >> M && V)
	{
		for (int i = 0; i < V; ++i)
		{
			G[i].clear();
		}
		for (int i = 0; i < M; ++i)
		{
			int u, v, d, c;
			cin >> u >> v >> d >> c;
			--u, --v;
			G[u].push_back(edge(v, d, c));
			G[v].push_back(edge(u, d, c));
		}
 
		cout << dijkstra(0) << endl;
	}
	return 0;
}
///////////////////////////End Sub//////////////////////////////////
