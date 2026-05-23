#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<set>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll, ll> pll;
//int dx[4] = { 1,0,0,-1 };
//int dy[4] = { 0,1,-1,0 };
#define MOD 1000000007
#define ARRAY_MAX 1005

const int INF = 1e9 + 7;


int main(){


	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<double> x(3), y(3);
	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}

	double maxi = 0;

	double len_sum = 0;

	for (int i = 0; i < 3; i++)
	{
		double len = (x[i % 3] - x[(i + 1) % 3])*(x[i % 3] - x[(i + 1) % 3]) + (y[i % 3] - y[(i + 1) % 3]) * (y[i % 3] - y[(i + 1) % 3]);
		len_sum += sqrt(len);
		maxi = max(maxi,len);
	}

	maxi = sqrt(maxi);

	double x1 = x[1] - x[0], x2 = x[2] - x[0];
	double y1 = y[1] - y[0], y2 = y[2] - y[0];

	double s = abs(x1 * y2 - y1 * x2) / 2;

	double r = 2 * s / (len_sum);

	double ans = (r*maxi) / (2 * r + maxi);

	printf("%.12f\n", ans);

	return 0;
}
