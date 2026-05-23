#include<iostream>
#include <list>
#include<stack>
#include<queue>
#include <vector>
#include <set>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include <functional>
#include<fstream>

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define LL long long
#define CLR(a) memset((a),0,sizeof(a))
#define SZ(x) (int((x).size()))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl
using namespace std;

const LL MOD = 1000000007;// 10^9+7
const int INF = (1 << 30);
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

class UnionFind {
public:
	vector<ll> parent;
	vector<ll> gap;//強化前の、素の値
	vector<ll> up;//強化量

	UnionFind(ll n) : parent(n), gap(n, 0), up(n, 0) {
		REP(i, 0, n) parent[i] = i;
	}

	ll find(ll i) {
		if (parent[i] == i) return i;

		int tmp = parent[i];
		ll p = find(parent[i]);
		//cerr << "find  " << i+1 << " ,," << tmp+1 << "p: " << p+1 << endl;
		gap[i] += gap[tmp];
		return parent[i] = p;
	}

	void unite(ll i, ll j, ll c) {
		ll p = find(i), q = find(j);
		if (p != q) {
			gap[p] = c + get(j) - get(i);
			parent[p] = q;
		}
		up[i] += c;
		up[j] += c;
	}

	ll get(ll i) {
		return  - up[i] + gap[i];
		//return up[find(i)] - up[i] + gap[i];
	}
};

int main(void) {
	ll N, Q;
	cin >> N >> Q;
	vector<ll> T(Q), A(Q), B(Q), C(Q);
	REP(i, 0, Q) {
		string type;
		cin >> type >> A[i] >> B[i]; A[i]--; B[i]--;
		if (type == "IN") {
			T[i] = 0;
			cin >> C[i];
		}
		if (type == "COMPARE") T[i] = 1;
	}

	UnionFind uf(N);
	REP(i, 0, Q) {
		//cerr << endl<<endl<<"   debug" << endl;
		if (T[i] == 0) {
			uf.unite(A[i], B[i], C[i]);
		}
		if (T[i] == 1) {
			if (uf.find(A[i]) != uf.find(B[i])) cout << "WARNING" << endl;
			else {
				//uf.find(A[i]);
				//uf.find(B[i]);
				//cerr << "testing" << endl;
				cout << uf.get(A[i]) - uf.get(B[i]) << endl;
			}
		}
		//cerr << "====" << endl;
		//cerr << "way::" << A[i]+1 << " " << B[i]+1 << endl;
		//REP(i, 0, N) cerr <<"me:"<<i+1<< " par:" << uf.parent[i] + 1 << ",  gap:" << uf.gap[i] << ",  up:" << uf.up[i] << endl;
	}
	//cerr << "==FINISH==" << endl;
	//REP(i, 0, N) cerr << "par:" << uf.parent[i] << ",  gap:" << uf.gap[i] << ",  up:" << uf.up[i] << endl;
	int n;
	cin >> n;

}
