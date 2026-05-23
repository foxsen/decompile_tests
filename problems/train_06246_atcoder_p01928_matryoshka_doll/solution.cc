#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

typedef long long  Weight;
struct Edge {
	int src, dest;
	int cap, rev;
	Weight weight;
	bool operator < (const Edge &rhs) const { return weight > rhs.weight; }
};

const int V = 4000;
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;
Weight h[V];                //ポテンシャル
Weight dist[V];             //最短距離
int prevv[V], preve[V];  //直前の辺と頂点

void add_edge(Graph &g, int src, int dest, int cap, Weight weight) {
	g[src].push_back(Edge{ src, dest, cap, (int)g[dest].size(), weight });
	g[dest].push_back(Edge{ dest, src, 0, (int)g[src].size() - 1, -weight });
}
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const Weight INF = 2147483647;
const Weight ZERO=0;
//コストがdoubleの時はeps使おう
Weight min_cost_flow(Graph &g, int s, int t, int f) {
	Weight res = ZERO;
	memset(h, ZERO, sizeof(h));
	typedef pair<Weight, int> P;
//ポテンシャルを先に計算して速度向上
//REP(i, g.size() / 2 - 1) {
//	int v = i + 2;
//	REP(j, g[v].size()) {
//		Edge &e = g[v][j];
//		if (e.cap == 0) continue;
//		int u = e.dest;
//		h[u] = min(h[u], h[v] + e.weight);
//	}
//	v = i + g.size() / 2 + 1;
//	REP(j, g[v].size()) {
//		Edge &e = g[v][j];
//		if (e.cap == 0) continue;
//		int u = e.dest;
//		h[u] = min(h[u], h[v] + e.weight);
//	}
//}
	while (f > 0) {
		priority_queue<P, vector<P>, greater<P> > que;
		fill(dist, dist + V, INF);
		dist[s] = 0;
		que.push(P(ZERO, s));
		while (!que.empty()) {
			P p = que.top(); que.pop();
			const int v = p.second;
			if (dist[v] < p.first) continue;
			REP(i, g[v].size()) {
				Edge &e = g[v][i];
				if (e.cap > 0 && dist[e.dest] > dist[v] + e.weight + h[v] - h[e.dest]) {
					dist[e.dest] = dist[v] + e.weight + h[v] - h[e.dest];
					prevv[e.dest] = v;
					preve[e.dest] = i;
					que.push(P(dist[e.dest], e.dest));
				}
			}
		}
		if (dist[t] == INF) return -1;
		for(int v=0;v<V;++v) h[v] = h[v] + dist[v];

		int d = f;
		for (int v = t; v != s; v = prevv[v]) d = min(d, g[prevv[v]][preve[v]].cap);
		f -= d;
		res = res + d * h[t];
		for (int v = t; v != s; v = prevv[v]) {
			Edge &e = g[prevv[v]][preve[v]];
			e.cap -= d;
			g[v][e.rev].cap += d;
		}
	}
	return res;
}

int ar(vector<int>&s) {
	return s[0]*s[1]*s[2];
}

int main()
{
	while (true) {
		int N;cin>>N;
		if(!N)break;
		vector<vector<int>>matos;
		for (int i = 0; i < N; ++i) {
			int a,b,c;cin>>a>>b>>c;
			matos.emplace_back(vector<int>{ a,b,c });
		}

		const int start=0;
		const int ma_in=start+1;
		const int ma_out=ma_in+N;
		const int goal=ma_out+N;
		Graph g(goal+1);
		for (int i = 0; i < N; ++i) {

			add_edge(g,start,ma_in+i,1,0);
			
			for (int j = 0; j < N; ++j) {
				auto mato_i(matos[i]);
				auto mato_j(matos[j]);

				vector<int>perms(3);
				iota(perms.begin(),perms.end(),0);

				bool ok=false;
				do {
					bool nok=true;
					for (int d = 0; d < 3; ++d) {
						if (mato_i[d] >= mato_j[perms[d]]) {
							nok=false;
						}
					}
					if(nok)ok=true;
				}while(next_permutation(perms.begin(),perms.end()));

				if (ok) {
					add_edge(g,ma_in+i,ma_out+j,1,0);
				}
			}

			add_edge(g,ma_in+i,goal,1,ar(matos[i]));
			add_edge(g,ma_out+i,goal,1,0);
		}

		int ans=min_cost_flow(g,start,goal,N);
		cout<<ans<<endl;
	}
	return 0;
}

