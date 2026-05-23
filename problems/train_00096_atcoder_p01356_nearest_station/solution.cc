#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-10;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"
int K, R, L;
ld P;
ld E;
ld T;


long long int atime(const long long int l, const long long int r) {
	if (l > LLONG_MAX / r) {
		return LLONG_MAX;
	}
	else {
		return l*r;
	}
}
long long int powint(long long int a, long long int b) {
	if (!b)return 1;
	else {
		return atime(a, powint(a, b - 1));
	}
}

long long int aplus(const long long int l, const long long int r) {
	if (l > LLONG_MAX / 3 || R > LLONG_MAX)return LLONG_MAX;
	else return l + r;
}
//ld getans(const ld amin, const ld amax,const int rest,const ld per) {
//	if (!rest||per<4e-8) {
//		return abs((amin + amax) / 2 - T) < E+eps;
//	}
//	if (amin > E + T+eps)return 0;
//	if (amax < T-E - eps)return 0;
//	if (amin > T - E - eps&&T + E + eps < amax)return 1;
//	ld amid = (amin + amax) / 2;
//	if (amid > T-eps) {
//		return getans(amin, amid,rest-1,per*(1-P))*(1-P) + getans(amid, amax,rest-1,per*P)*P;
//	}
//	else {
//		return getans(amin, amid, rest - 1,per*P)*P + getans(amid, amax, rest - 1,per*(1-P))*(1 - P);
//	}
//}

void getans(const vector<long long int>& sums,const vector<long long int>&tickets, const int now, long long int &ans,const long long int rest) {
	if (now == tickets.size()) {
		ans = min(ans, rest);
		return;
	}
	if (ans < rest - sums[now])return;
	
	if (rest >= tickets[now]) {
		getans(sums, tickets, now + 1, ans, rest - tickets[now]);
	}
	else {
		ans = min(ans, tickets[now] - rest);
	}
	getans(sums, tickets, now + 1, ans, rest);
}
int main() {
	//cin >> K >> R >> L;
	//cin >> P >> E >> T;
	//ld ans = getans(R, L, K,1);
	//cout << setprecision(22) << fixed << ans << endl;
	//return 0;
	long long int N, M, A, B, P, Q; cin >> N >> M >> A >> B >> P >> Q;
	if (A > B) {
		swap(A, B);
		swap(P, Q);
	}
	assert(A <= B);
	if (A == 1 && B == 1) {
		long long int ticdis = P + Q;
		if (atime(ticdis,N) <= M) {
			cout << M - atime(ticdis, N) << endl;
		}
		else {
			cout << min(ticdis-M%ticdis,M%ticdis) << endl;
		}
	}
	else {
		vector<long long int>tickets;
		long long	int ans = M;
		for (int k = 0; k < N; ++k) {
			long long int tic =aplus( atime(P, powint(A, k)), atime(Q, powint(B, k)));
			if (tic > M) {
				ans = min(ans, tic - M);
				break;
			}
			else {
				tickets.emplace_back(tic);
			}
		}
		reverse(tickets.begin(), tickets.end());
		vector<long long int>sums(tickets);
		for (int i = sums.size()-1; i >0; --i) {
			sums[i - 1] += sums[i];
		}
		getans(sums, tickets, 0, ans, M);
		cout << ans << endl;
	}
	return 0;
}