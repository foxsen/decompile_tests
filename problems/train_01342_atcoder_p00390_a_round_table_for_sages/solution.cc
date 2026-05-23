#include<iostream>
#include<vector>
#include<algorithm>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,s,e) for(int i=s;i<e;i++)

using namespace std;

int main(void) {
	int N, MINR = 1001, MINL = 1001;
	cin >> N;
	vector<int> a(N);
	vector<int> w(N);
	REP(i, N)cin >> a[i];
	REP(i, N)cin >> w[i];
	REP(i, N) {
		if (a[i] == 0 && w[i] < MINR)MINR = w[i];
		else if (a[i] == 1 && w[i] < MINL)MINL = w[i];
	}
	if (MINL == 1001 || MINR == 1001)cout << 0 << endl;
	else cout << MINL + MINR << endl;
	return 0;
}
