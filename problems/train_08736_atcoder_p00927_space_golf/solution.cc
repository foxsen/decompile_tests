#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cassert>
#include <functional>

using namespace std;

#define LOG(...) printf(__VA_ARGS__)
//#define LOG(...)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define CLR(a) memset((a), 0 ,sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int dx[] = { -1, 0, 1, 0 }; const int dy[] = { 0, 1, 0, -1 };

int main() {
	double d;
	int n, b;
	cin >> d >> n >> b;
	vector<pair<double, double>> obs(n);
	REP(i, n){
		cin >> obs[i].first >> obs[i].second;
	}
	double ans=1e8;
	REP(i,b+1){
		double ma=0.0;
		REP(j,n){
			double x = obs[j].first;
			double y = obs[j].second;
			while (x>d/(i+1)){
				x -= d / (i + 1);
			}
			

			double a = -(x*x) + d / (i + 1)*x;
			if (x > 0.0){
				if ((a / (2 * y) < (d / (i + 1))*(d / (i + 1))*y / (2 * a)))
					ma = max(ma, sqrt((a / (2 * y) + (d / (i + 1))*(d / (i + 1))*y / (2 * a))));
				else
					ma = max(ma,sqrt(d / (i + 1)));
			}
		}
		ans = min(ans, ma);
	}

		printf("%.5lf\n", ans);
}