#include "bits/stdc++.h"
using namespace std;
#define for_(i, s, e) for (int i = s; i < (int) e; i++)
#define for__(i, s, e) for (ll i = s; i < e; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define endl '\n'

int n, m;
const int MXN = 1e5, INF = 1e9;
const int block_size = 2000, block_size_init = 2000;
int freq[MXN+1], ffreq[MXN+1], done[MXN+1];
vi nums, curr;

struct Query {
	int l, r, k, idx;
	bool operator<(Query other) const {
		int b1 = l/block_size, b2 = other.l/block_size;
		if (b1 != b2) return b1 < b2;
		else if (b1 % 2 == 0) return r < other.r;
		else return r > other.r;
	}
};

void changeF(int &v, int d) {
	if (!v) return;
	ffreq[v] += d;
	assert(ffreq[v] >= 0);
	curr.push_back(v);
}

void add(int v) {
	changeF(freq[v], -1);
	freq[v] += 1;
	changeF(freq[v], 1);
}

void remove(int v) {
	changeF(freq[v], -1);
	freq[v] -= 1;
	changeF(freq[v], 1);
}

int main() {
#ifdef mlocal
	freopen("test.in", "r", stdin);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	nums.resize(n); memset(done, -1, sizeof(done));
	for_(i, 0, n) cin >> nums[i];
	int mb = (m/block_size_init)+1;
	
	vector<Query> queries[mb];
	vector<array<int, 3>> updates[mb];
	int ans[m];
	memset(ans, -1, sizeof(ans));
	
	for_(i, 0, m) {
		int t; cin >> t;
		if (t == 1) {
			Query q; cin >> q.l >> q.r >> q.k;
			q.l -= 1; q.r -= 1;
			q.idx = i;
			queries[i/block_size_init].push_back(q);
		} else {
			array<int, 3> q; cin >> q[0] >> q[1];
			q[0] -= 1;
			q[2] = i;
			updates[i/block_size_init].push_back(q);
		}
	}
	
	for_(i, 0, mb) sort(queries[i].begin(), queries[i].end());
	
	vi pre;
	int cur_l = 0, cur_r = -1;
	for_(i, 0, mb) {
		pre = nums;
		// process the queries
		for (auto q: queries[i]) {
			for (auto &j: updates[i]) {
				if (j[2] > q.idx) break;
				if (cur_l <= j[0] and cur_r >= j[0]) remove(nums[j[0]]);
				nums[j[0]] = j[1];
				if (cur_l <= j[0] and cur_r >= j[0]) add(nums[j[0]]);
			}
			
			while (cur_l > q.l) add(nums[--cur_l]);
			while (cur_r < q.r) add(nums[++cur_r]);
			while (cur_l < q.l) remove(nums[cur_l++]);
			while (cur_r > q.r) remove(nums[cur_r--]);
			
			vi temp;
			for (auto &j: curr) if (ffreq[j] and done[j] != q.idx) {
				done[j] = q.idx;
				temp.push_back(j);
			}
			
			swap(curr, temp);
			sort(curr.begin(), curr.end());
			int val = INF, r = 0, s = 0;
			for_(j, 0, curr.size()) {
				while (r < (int) curr.size() and s < q.k) {
					s += ffreq[curr[r]];
					r++;
				}
				
				if (s >= q.k) val = min(val, curr[r-1]-curr[j]);
				s -= ffreq[curr[j]];
			}
			ans[q.idx] = val;
			for (auto &j: updates[i]) {
				if (j[2] > q.idx) break;
				if (cur_l <= j[0] and cur_r >= j[0]) remove(nums[j[0]]);
				nums[j[0]] = pre[j[0]];
				if (cur_l <= j[0] and cur_r >= j[0]) add(nums[j[0]]);
			}
		}
		
		// apply the final updates
		for (auto &j: updates[i]) {
			if (cur_l <= j[0] and cur_r >= j[0]) remove(nums[j[0]]);
			nums[j[0]] = j[1];
			if (cur_l <= j[0] and cur_r >= j[0]) add(nums[j[0]]);
		}
	}
	
	for_(i, 0, m) if (ans[i] != -1) cout << (ans[i] == INF ? -1 : ans[i]) << endl;
	
	return 0;
}
