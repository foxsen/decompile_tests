#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

class Lowest_Common_Ancestor {
	vector<int>depth;
	vector<vector<int>>edge;
	int height = 0;
	int node;
public:
	vector<vector<int>>parent;
	Lowest_Common_Ancestor(int num) {
		num++;
		node = num;
		while (num) {
			height++;
			num /= 2;
		}
		parent.resize(height);
		edge.resize(node);
		depth.resize(node);
		for (int i = 0; i < height; i++)parent[i].resize(node);
	}
	void Add_Edge(int a, int b) {
		edge[a].push_back(b);
		edge[b].push_back(a);
		return;
	}
	void Update(int rtnode) {
		queue<int>QQ;
		for (int i = 0; i < node; i++) depth[i] = INT_MAX;
		depth[rtnode] = 0;
		QQ.push(rtnode);
		while (!QQ.empty()) {
			int c = QQ.front();
			for (auto i : edge[c]) {
				if (depth[i] > depth[c] + 1) {
					depth[i] = depth[c] + 1;
					QQ.push(i);
				}
			}
			QQ.pop();
		}
		parent[0][rtnode] = -1;
		for (int i = 0; i < node; i++) {
			for (auto j : edge[i]) {
				if (depth[i] - 1 == depth[j]) {
					parent[0][i] = j;
					break;
				}
			}
		}
		for (int i = 0; i < height - 1; i++) {
			for (int j = 0; j < node; j++) {
				if (parent[i][j] < 0)parent[i + 1][j] = -1;
				else parent[i + 1][j] = parent[i][parent[i][j]];
			}
		}
		return;
	}
	int LCA(int u, int v) {
		if (depth[u] > depth[v])swap(u, v);
		for (int i = 0; i < height; i++) {
			if ((depth[v] - depth[u]) >> i & 1) {
				v = parent[i][v];
			}
		}
		if (u == v)return u;
		for (int i = height - 1; i >= 0; i--) {
			if (parent[i][v] != parent[i][u]) {
				u = parent[i][u];
				v = parent[i][v];
			}
		}
		return parent[0][u];
	}
	int Dist(int u, int v) {
		return depth[u] + depth[v] - depth[LCA(u, v)] * 2;
	}
};

class Add_Segment_Tree {
	vector<long long int>v;
	long long int ret;
	int num;
	long long int Update(int place) {
		if (place >= v.size() / 2) {
			return v[place];
		}
		v[place] = Update(place * 2) + Update(place * 2 + 1);
		return v[place];
	}
public:
	Add_Segment_Tree(int n) {
		n++;
		num = 1;
		while (num < n * 2)num *= 2;
		v.resize(num, 0);
	}
	void Add(int place, long long int num, bool update) {
		place += v.size() / 2;
		v[place] += num;
		if (!update)return;
		place /= 2;
		while (place) {
			v[place] = v[place * 2] + v[place * 2 + 1];
			place /= 2;
		}
	}
	void TopDown() {
		Update(1);
	}
	long long int Sum(int a, int b) {
		ret = 0;
		b++;
		for (a += num / 2, b += num / 2; a < b; a >>= 1, b >>= 1) {
			if (a & 1)ret += v[a++];
			if (b & 1)ret += v[--b];
		}
		return ret;
	}
};


class EulerTour {	//	0-indexed
public:
	vector<int>tour;
	vector<int>depth;
	vector<int>l;
	vector<int>r;
private:
	int node;
	vector<vector<int>>edge;
	int root = 0;
	void DFS(int n) {
		tour.push_back(n);
		for (auto i : edge[n]) {
			if (depth[n] < depth[i]) {
				DFS(i);
			}
		}
		tour.push_back(n);
		return;
	}
	void BFS() {
		for (auto &i : depth)i = MOD;
		depth[root] = 0;
		queue<int>Q;
		Q.push(root);
		while (!Q.empty()) {
			int cn = Q.front();
			int c = depth[cn];
			Q.pop();
			for (auto i : edge[cn]) {
				if (depth[i] > c + 1) {
					depth[i] = c + 1;
					Q.push(i);
				}
			}
		}
		return;
	}
public:
	EulerTour(int n, int ro) {
		node = n;
		node++;
		root = ro;
		edge.resize(node);
		depth.resize(node, MOD);
		l.resize(node, MOD);
		r.resize(node, 0);
		return;
	}
	void Add_Edge(int a, int b) {
		edge[a].push_back(b);
		edge[b].push_back(a);
		return;
	}
	void Retour() {
		if (!tour.empty())tour.clear();
		BFS();
		DFS(root);
		for (int i = 0; i < tour.size(); i++) {
			l[tour[i]] = min(l[tour[i]], i);
			r[tour[i]] = max(r[tour[i]], i);
		}
		return;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<pair<int, int>>>edge(N);
	Lowest_Common_Ancestor lca(N);
	EulerTour et(N, 0);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		L--;
		edge[L].push_back({ i,R });
		edge[i].push_back({ L,R });
		lca.Add_Edge(i, L);
		et.Add_Edge(i, L);
	}
	lca.Update(0);
	et.Retour();
	Add_Segment_Tree asg(et.tour.size());
	vector<long long int>depth(N, MOD*MOD);
	vector<int>step(N, MOD);
	step[0] = 0;
	depth[0] = 0;
	queue<int>Q;
	Q.push(0);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (depth[i.first] > depth[cn] + i.second) {
				depth[i.first] = depth[cn] + i.second;
				step[i.first] = step[cn] + 1;
				Q.push(i.first);
			}
		}
	}
	long long int ans = 0;
	long long int p = 0;
	cout << ans << endl;
	asg.Add(et.l[0], 1, true);
	for (int i = 1; i < N; i++) {
		asg.Add(et.l[i], 1, true);
		int l = lca.LCA(p, i);
		ans -= depth[l] * 2;
		ans += depth[p];
		ans += depth[i];
		//cout << ans << endl;
		auto  sump = asg.Sum(et.l[p], et.r[p]);
		if (i == p) {

		}
		else if (l == p) {//今いる場所の下に追加
			int nx = i;
			int dis = step[i] - step[p] - 1;
			for (int j = lca.parent.size() - 1; j >= 0; j--) {
				if (dis >= (1 << j) && asg.Sum(et.l[lca.parent[j][nx]], et.r[lca.parent[j][nx]]) * 2 <= i) {
					nx = lca.parent[j][nx];
					dis -= 1 << j;
				}
			}
			if (asg.Sum(et.l[nx], et.r[nx]) * 2 <= i)nx = lca.parent[0][nx];
			ans -= (depth[p] - depth[nx])*(i + 1 - asg.Sum(et.l[nx], et.r[nx]) * 2);
			p = nx;
		}
		else {//それ以外
			int nx = p;
			int dis = step[p] - step[l] - 1;
			for (int j = lca.parent.size() - 1; j >= 0; j--) {
		//		cout << dis << endl;
				if (dis >= (1 << j) && asg.Sum(et.l[lca.parent[j][nx]], et.r[lca.parent[j][nx]]) * 2 <= i) {
					nx = lca.parent[j][nx];
					dis -= 1 << j;
				}
			}
			//cout << "fst " << nx << " " << asg.Sum(et.l[nx], et.r[nx]) << endl;
			if (asg.Sum(et.l[nx], et.r[nx]) * 2 <= i)nx = lca.parent[0][nx];
			//cout <<"snd "<< nx <<" "<< asg.Sum(et.l[nx], et.r[nx]) << endl;
			if (nx != l) {//lcaを跨がない
				ans += (depth[nx] - depth[p])*(i + 1 - sump * 2);
				p = nx;
			}
			else {//lcaを跨ぐ
				int dis = step[i] - step[l] - 1;
				if (dis > 0) {
				//	cout << "dis " << dis << endl;
					nx = i;
				//	cout << "nx " << nx << endl;
					for (int j = lca.parent.size() - 1; j >= 0; j--) {
						if (dis >= (1 << j) && asg.Sum(et.l[lca.parent[j][nx]], et.r[lca.parent[j][nx]]) * 2 <= i) {
							nx = lca.parent[j][nx];
							dis -= 1 << j;
						}
					}
				//	cout << "nxsnd " << nx << endl;
				}
				if (asg.Sum(et.l[nx], et.r[nx]) * 2 <= i)nx = lca.parent[0][nx];
				ans += (depth[l] * 2 - depth[nx] - depth[p])*(i + 1 - sump * 2);
				p = nx;
			}
		}
		//cout << ans << " " << p << endl;
		cout << ans << endl;
	}
}
