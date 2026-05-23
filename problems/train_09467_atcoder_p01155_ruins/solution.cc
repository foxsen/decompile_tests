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
	int x, y;
	while (cin >> x >> y, x){
		vector<int> xv;
		vector<int> yv;
		for (int i = 1; i <= sqrt(x); i++){
			if (x%i == 0)xv.push_back(i);
		}
		for (int i = 1; i <= sqrt(y); i++){
			if (y%i == 0)yv.push_back(i);
		}
		vector<int> calc(4);
		int ans = 1000000007;
		REP(i, xv.size()){
			REP(j, yv.size()){
				calc[0] = xv[i];
				calc[1] = x / xv[i];
				calc[2] = yv[j];
				calc[3] = y / yv[j];
				SORT(calc);
				ans = min(ans, (calc[0] - calc[1])*(calc[0] - calc[1]) + (calc[2] - calc[1])*(calc[2] - calc[1]) + (calc[3] - calc[2])*(calc[3] - calc[2]));
			}
		}
		cout << ans << endl;
	}
}