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
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

class Partition {
	class List {
		int cur;
		const vector<int> &next;

	public:
		List(int cur, const vector<int> &next) : cur(cur), next(next) {}
		List begin() const { return *this; }
		List end() const { return List(-1, next); }
		int operator*() const { return cur; }
		List &operator++() { cur = next[cur]; return *this; }
		bool operator!=(const List &that) const { return cur != that.cur; }
	};

public:
	int getGroundSize() const { return (int)name.size(); }
	int getNumberOfSets() const { return (int)head.size(); }

	int getSize(int i) const { return size[i]; }
	int getName(int i) const { return name[i]; }
	List getList(int i) const { return List(head[i], next); }

	void init(int n) {
		head.assign(1, 0);
		size.assign(1, n);
		next.resize(n), prev.resize(n);
		name.assign(n, 0);
		head[0] = 0;
		rep(i, n) {
			next[i] = i == n - 1 ? -1 : i + 1;
			prev[i] = i - 1;
		}
	}

	int addEmptySet() {
		int i = (int)head.size();
		head.push_back(-1);
		size.push_back(0);
		return i;
	}

	void moveElement(int element, int id) {
		remove(element);
		insert(element, id);
	}

private:
	vector<int> head, size;
	vector<int> next, prev;
	vector<int> name;

	void remove(int a) {
		int p = prev[a], n = next[a], x = name[a];
		if(n != -1)
			prev[n] = p;
		if(p != -1)
			next[p] = n;
		else
			head[x] = n;
		prev[a] = next[a] = -1;
		-- size[x];
		name[a] = -1;
	}

	void insert(int a, int x) {
		int n = head[x];
		if(n != -1)
			prev[n] = a;
		head[x] = a;
		prev[a] = -1;
		next[a] = n;
		++ size[x];
		name[a] = x;
	}
};

typedef char Letter;

struct Transition {
	int state;
	Letter letter;
	Transition() {}
	Transition(int state, Letter letter) : state(state), letter(letter) {}
};

template<typename Val>
struct TransitionMap {
	const int Alphas = 2, AlphaBase = '0';
	vector<Val> vec;

	TransitionMap(int n) : vec(n * Alphas) {}
	Val &operator[](Transition t) { return vec[t.state * Alphas + (t.letter - AlphaBase)]; }
	Val get(Transition t) const { return vec[t.state * Alphas + (t.letter - AlphaBase)]; }
};

void stabilize(const vector<vector<Transition>> &graph, Partition &partition) {
	Letter letters[] = {'0', '1'};

	int n = (int)graph.size(), maxPartitions = max(n, 2);
	assert(partition.getGroundSize() == n);
	assert(partition.getNumberOfSets() == 2);
	assert(partition.getSize(0) + partition.getSize(1) == n);
	TransitionMap<vector<int>> invGraph(n);
	rep(i, n) for(const auto &e : graph[i]) {
		Transition t(e.state, e.letter), u(partition.getName(e.state), e.letter);
		invGraph[t].emplace_back(i);
	}
	vector<bool> onQueue(maxPartitions);
	vector<int> que;
	int firstSet = partition.getSize(0) < partition.getSize(1) ? 0 : 1;
	que.push_back(firstSet);
	onQueue[firstSet] = true;
	vector<int> A, X, Ys;
	vector<vector<int>> intersection(maxPartitions);
	vector<bool> setVisited(maxPartitions), stateVisited(n);
	for(int qh = 0; qh != que.size(); ) {
		int setA = que[qh ++];
		onQueue[setA] = false;
		A.clear();
		for(int a : partition.getList(setA))
			A.push_back(a);
		for(int c : letters) {
			X.clear();
			for(int p : A) {
				for(int x : invGraph.get(Transition(p, c)))
					X.push_back(x);
			}
			Ys.clear();
			for(int x : X) {
				int setY = partition.getName(x);
				if(!setVisited[setY]) {
					Ys.push_back(setY);
					setVisited[setY] = true;
				}
				if(!stateVisited[x]) {
					intersection[setY].push_back(x);
					stateVisited[x] = true;
				}
			}
			for(int setY : Ys) {
				int YSize = partition.getSize(setY);
				int intersectionSize = (int)intersection[setY].size();
				if(intersectionSize == YSize)
					continue;
				int newSet = partition.addEmptySet();
				for(int y : intersection[setY])
					partition.moveElement(y, newSet);
				if(onQueue[setY]) {
					que.push_back(newSet);
					onQueue[newSet] = true;
				} else {
					int smallSet = YSize - intersectionSize < intersectionSize ? setY : newSet;
					que.push_back(smallSet);
					onQueue[smallSet] = true;
				}
			}
			for(int setY : Ys) {
				setVisited[setY] = false;
				for(int y : intersection[setY])
					stateVisited[y] = false;
				intersection[setY].clear();
			}
		}
	}
}

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<vector<Transition>> graph(n);
		vector<int> initpart(n);
		rep(i, n) {
			int v; int s; int t;
			scanf("%d%d%d", &v, &s, &t);
			initpart[i] = v;
			graph[i].emplace_back(s, '0');
			graph[i].emplace_back(t, '1');
		}
		Partition partition; partition.init(n);
		partition.addEmptySet();
		rep(i, n) if(initpart[i] == 1)
			partition.moveElement(i, 1);
		stabilize(graph, partition);
		rep(i, m) {
			int q;
			scanf("%d", &q);
			int ans = partition.getSize(partition.getName(q));
			printf("%d\n", ans);
		}
	}
	return 0;
}