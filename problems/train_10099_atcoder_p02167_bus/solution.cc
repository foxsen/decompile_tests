#include <iostream>
#include <vector>
#include <algorithm>

#define llint long long
#define inf 1e18

using namespace std;

typedef pair<llint, llint> P;

struct LiChaoTree{
	int size;
	vector<P> seg;
	vector<llint> x;
	
	LiChaoTree(){}
	LiChaoTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		x.resize(1<<size);
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = make_pair(0, inf);
		for(int i = 0; i < (1<<size); i++) x[i] = i;
	}
	llint calc(P f, llint x)
	{
		return f.first * x + f.second;
	}
	llint query(int i) //x[i]における最小値を取得
	{
		llint X = x[i], ret = inf;
		i += (1 << size);
		while(i >= 1){
			ret = min(ret, calc(seg[i], X));
			i /= 2;
		}
		return ret;
	}
	void add(int k, int l, int r, P f)
	{
		int m = (l+r)/2;
		if(calc(f, x[m]) < calc(seg[k], x[m])) swap(seg[k], f);
		bool L = (calc(f, x[l]) < calc(seg[k], x[l])), R = (calc(f, x[r]) < calc(seg[k], x[r]));
		if(L == R) return;
		if(L) add(k*2, l, m, f);
		if(R) add(k*2+1, m+1, r, f);
	}
	void addSegment(int a, int b, int k, int l, int r, P f)
	{
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			add(k, l, r, f);
			return;
		}
		addSegment(a, b, k*2, l, (l+r)/2, f);
		addSegment(a, b, k*2+1, (l+r)/2+1, r, f);
	}
	void addSegment(int a, int b, llint p, llint q) //区間[x[a], x[b]]に線分px+qを追加
	{
		addSegment(a, b, 1, 0, (1<<size)-1, make_pair(p, q));
	}
	void addLine(llint p, llint q) //直線px+qを追加
	{
		return addSegment(0, (1<<size)-1, p, q);
	}
};

llint n, m, Q, L;
llint p[100005], np[100005];
char c[100005];
llint b[100005], t[100005];
llint x[100005], y[100005];
llint ans[100005];
vector<llint> qvec[100005], bvec[100005];
vector<llint> comp;
LiChaoTree lct(17);

llint dist(llint s, llint t)
{
	if(t >= s) return t-s;
	else return t-s+L;
}

void solve()
{
	for(int i = 0; i < n; i++) qvec[i].clear();
	for(int i = 1; i <= Q; i++) qvec[x[i]].push_back(i);
	
	for(int i = 0; i < n; i++) bvec[i].clear();
	for(int i = 1; i <= m; i++){
		if(c[i] == 'R') bvec[b[i]].push_back(i);
	}
	
	comp.clear();
	for(int i = 1; i <= Q; i++) comp.push_back(p[x[i]]+dist(p[x[i]], p[y[i]]));
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	int N = comp.size();
	
	lct.init();
	for(int i = 0; i < (1<<17); i++){
		if(i < N) lct.x[i] = comp[i];
		else lct.x[i] = 1e9;
	}
	
	for(int i = 1; i <= m; i++){
		if(c[i] == 'R') lct.addLine(t[i], -(p[b[i]]-L)*t[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < bvec[i].size(); j++){
			int bid = bvec[i][j];
			lct.addLine(t[bid], -(p[b[bid]])*t[bid]);
		}
		for(int j = 0; j < qvec[i].size(); j++){
			int qid = qvec[i][j];
			llint id = lower_bound(comp.begin(), comp.end(), p[x[qid]] + dist(p[x[qid]], p[y[qid]])) - comp.begin();
			ans[qid] = min(ans[qid], lct.query(id));
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> Q;
	llint d;
	for(int i = 0; i < n; i++){
		cin >> d;
		p[i] = L;
		L += d;
	}
	for(int i = 1; i <= m; i++) cin >> c[i] >> b[i] >> t[i], b[i]--;
	for(int i = 1; i <= Q; i++) cin >> x[i] >> y[i], x[i]--, y[i]--;
	for(int i = 1; i <= Q; i++) ans[i] = inf;
	
	solve();
	
	for(int i = 1; i < n; i++) np[i] = L-p[n-i];
	for(int i = 0; i < n; i++) p[i] = np[i];
	for(int i = 1; i <= m; i++){
		if(c[i] == 'L') c[i] = 'R';
		else c[i] = 'L';
		if(b[i] > 0) b[i] = n-b[i];
	}
	for(int i = 1; i <= Q; i++){
		if(x[i] > 0) x[i] = n-x[i];
		if(y[i] > 0) y[i] = n-y[i];
	}
	
	solve();
	
	for(int i = 1; i <= Q; i++) cout << ans[i] << "\n";
	flush(cout);
	
	return 0;
}
