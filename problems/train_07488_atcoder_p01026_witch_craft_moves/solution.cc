#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if 1 || defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct CentroidPathDecomposition {
	vector<int> colors, positions;	//Vertex -> Color, Vertex -> Offset
	vector<int> lengths, parents, branches;	//Color -> Int, Color -> Color, Color -> Offset
	vector<int> parentnodes, depths;	//Vertex -> Vertex, Vertex -> Int
	//vector<FenwickTree>とかを避けて1次元にしたい時に使う
	vector<int> sortednodes, offsets;	//Index -> Vertex, Color -> Index

	//両方の辺があってもいいし、親から子への辺だけでもよい
	void build(const vector<vi> &g, int root) {
		int n = g.size();

		colors.assign(n, -1); positions.assign(n, -1);
		lengths.clear(); parents.clear(); branches.clear();
		parentnodes.assign(n, -1); depths.assign(n, -1);

		vector<int> subtreesizes;
		measure(g, root, subtreesizes);

		struct State {
			int i, len, parent;
			State() { }
			State(int i_, int l, int p): i(i_), len(l), parent(p) { }
		};
		depths[root] = 0;
		vector<State> s;
		s.push_back(State(root, 0, -1));
		while(!s.empty()) {
			State t = s.back(); s.pop_back();
			int i = t.i, len = t.len;
			int color = lengths.size();
			if(t.parent != -2) {
				assert(parents.size() == color);
				parents.push_back(t.parent);
				branches.push_back(len);
				len = 0;
			}
			colors[i] = color;
			positions[i] = len;

			int maxsize = -1, maxj = -1;
			each(j, g[i]) if(colors[*j] == -1) {
				if(maxsize < subtreesizes[*j]) {
					maxsize = subtreesizes[*j];
					maxj = *j;
				}
				parentnodes[*j] = i;
				depths[*j] = depths[i] + 1;
			}
			if(maxj == -1) {
				lengths.push_back(len + 1);
			}else {
				each(j, g[i]) if(colors[*j] == -1 && *j != maxj)
					s.push_back(State(*j, len, color));
				s.push_back(State(maxj, len + 1, -2));
			}
		}

		sortNodes();
	}

	void sortNodes() {
		int n = colors.size(), m = lengths.size();
		sortednodes.resize(n, -1);
		offsets.resize(m + 1);
		rep(i, m) offsets[i+1] = offsets[i] + lengths[i];
		rep(i, n) sortednodes[offsets[colors[i]] + positions[i]] = i;
	}

	void get(int v, int &c, int &p) const {
		c = colors[v]; p = positions[v];
	}
	bool go_up(int &c, int &p) const {
		p = branches[c]; c = parents[c];
		return c != -1;
	}

	inline const int *nodesBegin(int c) const { return &sortednodes[0] + offsets[c]; }
	inline const int *nodesEnd(int c) const { return &sortednodes[0] + offsets[c+1]; }

private:
	void measure(const vector<vi> &g, int root, vector<int> &out_subtreesizes) const {
		out_subtreesizes.assign(g.size(), -1);
		vector<int> s;
		s.push_back(root);
		while(!s.empty()) {
			int i = s.back(); s.pop_back();
			if(out_subtreesizes[i] == -2) {
				int s = 1;
				each(j, g[i]) if(out_subtreesizes[*j] != -2)
					s += out_subtreesizes[*j];
				out_subtreesizes[i] = s;
			}else {
				s.push_back(i);
				each(j, g[i]) if(out_subtreesizes[*j] == -1)
					s.push_back(*j);
				out_subtreesizes[i] = -2;
			}
		}
	}
};


typedef int Vertex;
struct Graph {
	typedef std::pair<Vertex, Vertex> Edge;
	struct To {
		Vertex to;
	};

	int n, m;

	Graph(int n_, const std::vector<Edge> &edges):
		n(n_), m(edges.size()), tos(m+1), offsets(n+1, 0) {
		for(int e = 0; e < m; e ++) offsets[edges[e].first] ++;
		for(int v = 1; v <= n; v ++) offsets[v] += offsets[v-1];
		for(int e = 0; e < m; e ++)
			tos[-- offsets[edges[e].first]].to = edges[e].second;
	}

	inline const To *edgesBegin(int v) const { return &tos[offsets[v]]; }
	inline const To *edgesEnd(int v) const { return &tos[offsets[v+1]]; }

	inline const int outDegree(int v) const { return offsets[v+1] - offsets[v]; }

private:
	std::vector<To> tos;
	std::vector<int> offsets;
};
	
class SchieberVishkinLCA {
public:
	typedef unsigned Word;
private:

	static inline Word lowestOneBit(Word v) {
		return v & (~v+1);
	}
	static inline Word highestOneBitMask(Word v) {
		v |= v >> 1;
		v |= v >> 2;
		v |= v >> 4;
		v |= v >> 8;
		v |= v >> 16;
		return v >> 1;
	}

	std::vector<Word> indices;			//Vertex -> index
	std::vector<Word> maxHIndices;		//Vertex -> index
	std::vector<Word> ancestorHeights;	//Vertex -> Word
	std::vector<Vertex> pathParents;	//index-1 -> Vertex
public:
	//gは親→子の枝のある根付き木
	void build(const Graph &g, Vertex root) {
		assert(g.m == g.n - 1);

		ancestorHeights.resize(g.n);
		std::vector<Vertex> parents(g.n);
		maxHIndices.resize(g.n);
		std::vector<Vertex> vertices; vertices.reserve(g.n);
		indices.resize(g.n);

		//euler tour
		Word currentIndex = 1;
		parents[root] = root;	//利便さのために
		vertices.push_back(root);
		while(!vertices.empty()) {
			Vertex v = vertices.back(); vertices.pop_back();
			indices[v] = currentIndex ++;
			for(const Graph::To *it = g.edgesBegin(v); it != g.edgesEnd(v); ++ it) {
				parents[it->to] = v;
				vertices.push_back(it->to);
			}
		}

		//BFS (トポロジカル順序を求めるために)
		int head = 0, tail = 1;
		vertices.resize(g.n); vertices[0] = root;
		while(head != tail) {
			Vertex v = vertices[head ++];
			for(const Graph::To *it = g.edgesBegin(v); it != g.edgesEnd(v); ++ it)
				vertices[tail ++] = it->to;
		}

		//深い方から
		for(std::vector<Vertex>::const_iterator it = vertices.begin(); it != vertices.end(); ++ it)
			maxHIndices[*it] = indices[*it];
		for(std::vector<Vertex>::const_reverse_iterator it = vertices.rbegin(); it != vertices.rend(); ++ it) {
			Vertex v = *it, parent = parents[v];
			if(lowestOneBit(maxHIndices[parent]) < lowestOneBit(maxHIndices[v]))
				maxHIndices[parent] = maxHIndices[v];
		}

		//Aを求める
		ancestorHeights[root] = 0;
		for(std::vector<Vertex>::const_iterator it = vertices.begin(); it != vertices.end(); ++ it) {
			Vertex v = *it;
			ancestorHeights[v] = ancestorHeights[parents[v]] | lowestOneBit(maxHIndices[v]);
		}

		pathParents.swap(parents);	//メモリをけちる
		pathParents[indices[root]-1] = root;
		for(std::vector<Vertex>::const_iterator it = vertices.begin(); it != vertices.end(); ++ it) {
			Vertex v = *it;
			for(const Graph::To *jt = g.edgesBegin(v); jt != g.edgesEnd(v); ++ jt) {
				if(maxHIndices[v] != maxHIndices[jt->to])
					pathParents[indices[jt->to]-1] = v;
				else
					pathParents[indices[jt->to]-1] = pathParents[indices[v]-1];
			}
		}
	}

	Vertex query(Vertex v, Vertex u) const {
		//binary tree上でのLCAの高さを求める
		Word Iv = maxHIndices[v], Iu = maxHIndices[u];
		Word hIv = lowestOneBit(Iv), hIu = lowestOneBit(Iu);
		Word hbMask = highestOneBitMask((Iv ^ Iu) | hIv | hIu);
		Word j = lowestOneBit(ancestorHeights[v] & ancestorHeights[u] & ~hbMask);
		//j = hI(lca(v,u)) となる (ここで、hI(x) = 2^(complete binary tree上でのI(x)の高さ), I(x) = maxHIndices[x])
		//(hI(lca(v,u)) = j)はhI(v)かhI(u)かその他の最大値。そして一意であることを考えると…
		Vertex x, y;
		if(j == hIv) x = v;
		else {			//lcaはvのパス上には無い
			Word kMask = highestOneBitMask(ancestorHeights[v] & (j-1));	//vの祖先で、jよりは低いけどその中で一番上にあるパス
			x = pathParents[(indices[v] & ~kMask | (kMask+1))-1];	//indices[v]のkの高さの祖先のパスの親
		}
		if(j == hIu) y = u;
		else {			//lcaはuのパス上には無い
			Word kMask = highestOneBitMask(ancestorHeights[u] & (j-1));	//uの祖先で、jよりは低いけどその中で一番上にあるパス
			y = pathParents[(indices[u] & ~kMask | (kMask+1))-1];	//indices[u]のkの高さの祖先のパスの親
		}
		return indices[x] < indices[y] ? x : y;	//in-orderなので、インデックスが低い方が祖先なはず
	}
};

struct FenwickTree {
	typedef long long T;
	vector<T> v;
	FenwickTree() { }
	void init(int n) { v.assign(n, 0); }
	void add(int i, T x) {
		for(; i < (int)v.size(); i |= i+1) v[i] += x;
	}
	T sum(int i) {	//[0, i)
		T r = 0;
		for(-- i; i >= 0; i = (i & (i+1)) - 1) r += v[i];
		return r;
	}
	T sum(int left, int right) {	//[left, right)
		return sum(right) - sum(left);
	}
};

void direct_tree(const vector<vi> &g, int i, int parent, vector<pii> &out_edges) {
	each(j, g[i]) if(*j != parent) {
		out_edges.pb(mp(i, *j));
		direct_tree(g, *j, i, out_edges);
	}
}

int cost[2000];
int main() {
	int N;
	scanf("%d", &N);
	rep(i, N) scanf("%d", &cost[i]);
	vector<vi> g(N);
	rep(i, N-1) {
		int a, b;
		scanf("%d%d", &a, &b); a --, b --;
		g[a].pb(b); g[b].pb(a);
	}
	vector<Graph::Edge> edges;
	direct_tree(g, 0, -1, edges);
	SchieberVishkinLCA lca; lca.build(Graph(N, edges), 0);
	CentroidPathDecomposition cpd; cpd.build(g, 0);
	vector<FenwickTree> ft(cpd.lengths.size());
	rep(i, ft.size())
		ft[i].init(cpd.lengths[i]);
	rep(i, N) {
		int c, p;
		cpd.get(i, c, p);
		ft[c].add(p, cost[i]);
	}
	int Q;
	scanf("%d", &Q);
	rep(ii, Q) {
		int t;
		scanf("%d", &t);
		if(t == 0) {
			int A, B;
			scanf("%d%d", &A, &B); A --, B --;
			int C = lca.query(A, B);
			int c, p, lc, lp;
			cpd.get(C, lc, lp);
			cpd.get(A, c, p);
			ll ans = 0;
			while(1) {
				int up = c != lc ? 0 : lp;
				ans += ft[c].sum(up, p+1);
				if(c == lc) break;
				cpd.go_up(c, p);
			}
			cpd.get(B, c, p);
			while(1) {
				int up = c != lc ? 0 : lp+1;
				ans += ft[c].sum(up, p+1);
				if(c == lc) break;
				cpd.go_up(c, p);
			}
			printf("%lld\n", ans);
		}else {
			int A, C;
			scanf("%d%d", &A, &C); A --;
			int c, p;
			cpd.get(A, c, p);
			ft[c].add(p, C);
		}
	}
	return 0;
}
