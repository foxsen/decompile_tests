#include <iostream>
#include <iomanip>
#include<vector>
#include <algorithm>
#include <queue>
#include<string>
#include <map>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <set>
typedef long long ll;
typedef long double ld;


#define REP(i,s,n)for(ll i=s;i<(n);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;
ll S[1000] = { 0 };
ll N,M,Q;


int main() {
	vector<ll>A;
	cin >> N;
	rep(i, N) {
		ll a;
		cin >> a;
		A.push_back(a);
	}
	vector<ll>B;
	cin >> M;
	rep(i, M) {
		ll b;
		cin >> b;
		B.push_back(b);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.begin());
	vector<ll>C;
	set_symmetric_difference(A.begin(),A.end(),B.begin(),B.end(),back_inserter(C));
	for (int i = 0; i <C.size();++i) {
		cout << C[i] << endl;
	}
	return 0;
}
