//ランタイムエラーの原因が分からなかったので、もしやと思い、sortをstable_sortに書き換えたらAcceptedした。なぜsortではダメなのか、よくわからない…
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
typedef pair<int, int> P;

/*https://kimiyuki.net/blog/2016/04/09/arc-050-d/より引用*/
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < (n); ++(i))
vector<int> suffix_array(string const & s) {
    int n = s.length();
    vector<int> sa(n+1);
    vector<int> rank(n+1);
    repeat (i,n+1) {
        sa[i] = i;
        rank[i] = i < n ? s[i] : -1;
    }
    auto rankf = [&](int i) { return i <= n ? rank[i] : -1; };
    vector<int> nxt(n+1);
    for (int k = 1; k <= n; k <<= 1) {
        auto cmp = [&](int i, int j) { return make_pair(rank[i], rankf(i + k)) < make_pair(rank[j], rankf(j + k)); };
        sort(sa.begin(), sa.end(), cmp);
        nxt[sa[0]] = 0;
        repeat_from (i,1,n+1) {
            nxt[sa[i]] = nxt[sa[i-1]] + (cmp(sa[i-1], sa[i]) ? 1 : 0);
        }
        rank.swap(nxt);
    }
    return sa;
}
/*終わり*/

/*ローリングハッシュ https://odan3240.hatenablog.com/entry/2015/02/16/111938*/
struct RollingHash {
    typedef long long int_type;
    typedef pair<int_type,int_type> hash_type;

    int_type base1;
    int_type base2;
    int_type mod1;
    int_type mod2;
    vector<int_type> hash1;
    vector<int_type> hash2;
    vector<int_type> pow1;
    vector<int_type> pow2;

    RollingHash() : base1(1009), base2(1007), mod1(1000000007), mod2(1000000009) {}

    void init(const string &s) {
        int n = s.size();

        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        pow1.assign(n+1,1);
        pow2.assign(n+1,1);

        for(int i=0;i<n;i++) {
            hash1[i+1] = (hash1[i]+s[i]) * base1 % mod1;
            hash2[i+1] = (hash2[i]+s[i]) * base2 % mod2;
            pow1[i+1] = pow1[i] * base1 % mod1;
            pow2[i+1] = pow2[i] * base2 % mod2;
        }
    }

	//[l, r)のハッシュ値を返す
    hash_type get(int l,int r) {
        int_type t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
        int_type t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
        return make_pair(t1, t2);
    }
};
/*終わり*/

int n, h;
string s;
int rs[100001];
int imos[100005];	//imos[i] = i桁の数字が何個あるか
vector<int> sa;
vector<int> saInv;	//saInv[i] = sa[id] = iなるidを書いておく
RollingHash rh;

bool compare(const P &l, const P &r) {
	if (rh.get(l.first, l.second) == rh.get(r.first, r.second)) return true;
	if (saInv[l.first] < saInv[r.first]) return true;
	return false;
}

signed main() {
	int i;
	
	cin >> n >> h >> s;
	for (i = 0; i < n; i++) rs[i + 1] = rs[i] + (s[i] > '0');
	
	for (i = 0; i < n; i++) {
		int st = i, ed = n + 1, mid; //(st, ed]
		while (ed - st >= 2) {
			mid = (st + ed) / 2;
			if (rs[mid] - rs[i] >= 1) ed = mid;
			else st = mid;
		}
		if (s[i] == '0') { imos[0] += ed - i - 1; imos[1] -= ed - i - 1; }
		imos[1]++;
		imos[n + 2 - ed]--;
	}
	
	for (i = 0; i <= n + 1; i++) imos[i + 1] += imos[i];
	//cout << "imos:" << endl;
	//for (i = 0; i <= n; i++) cout << imos[i] << endl;
	//cout << "imos*" << endl;
	
	for (i = 0; i <= n; i++) {
		h -= imos[i];
		if (h <= 0) break;
	}
	
	int keta = i;		//答えはi桁。
	if (keta == 0) { cout << 0 << endl; return 0; }
	//cout << "keta, h = " << keta << ", " << h << endl;
	
	vector<P> kukan;	//答えの候補 … [l, r)
	
	for (i = 0; i < n; i++) {
		int st = i, ed = n + 1, mid; //(st, ed]
		while (ed - st >= 2) {
			mid = (st + ed) / 2;
			if (rs[mid] - rs[i] >= 1) ed = mid;
			else st = mid;
		}
		if (ed + keta - 1 <= n) {
			kukan.push_back(P(ed - 1, ed + keta - 1));
		}
	}
	
	//cout << "ソート前" << endl;
	//for (i = 0; i < kukan.size(); i++) { cout << kukan[i].first << " " << kukan[i].second << endl; }
	
	sa = suffix_array(s);
	saInv.resize(sa.size());
	for (i = 0; i < sa.size(); i++) saInv[sa[i]] = i;
	//for (i = 0; i < sa.size(); i++) { cout << "sa[" << i << "] = " << sa[i] << endl; }
	rh.init(s);
	//for (i = 0; i < n; i++) for (int j = 0; j < n; j++) cout << "[" << i << ", " << j << "] = " << rh.get(i, j).first << endl;
	
	//kukanをソートしたい。その比較関数にsuffix_array, ローリングハッシュを用いる.
	stable_sort(kukan.begin(), kukan.end(), compare);
	//cout << "ソート後" << endl;
	//for (i = 0; i < kukan.size(); i++) { cout << kukan[i].first << " " << kukan[i].second << endl; }
	
	//あとは、適当に答えるだけ。
	int id = (int)kukan.size() - 1 + h;
	bool flag = false;
	for (i = kukan[id].first; i < kukan[id].second; i++) {
		if (s[i] != '0') flag = true;
		if (flag) cout << s[i];
	}
	cout << endl;
	return 0;
}
