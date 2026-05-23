#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define MP make_pair

int main() {
	while (true) {
		int n;
		pair<int, double> ans = MP(0, (1<<29));
		cin >> n;
		if (n == 0) break;

		REP(i, n) {
			double a, b, c, bmi;
			scanf("%lf %lf %lf", &a, &b, &c);
			bmi = c / (b/100 * b/100);

			if (ans.second > abs(22 - bmi)) {
				ans.first = a;
				ans.second = abs(22 - bmi);
			}
		}
		cout << ans.first << endl;
	}
	return 0;
}