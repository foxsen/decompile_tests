#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int INF = 1001001001;

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	int m;
	while(scanf("%d", &m), m){
		int dist[10], velo[10];
		rep(i, m){
			int a, b;
			scanf("%d%d", &a, &b);
			dist[i] = a / gcd(a, b);
			velo[i] = b / gcd(a, b);
		}
		
		ll n=dist[0], d=velo[0];
		reps(i, 1, m){
			ll nn = n * dist[i];
			ll nd = gcd(n*velo[i], d*dist[i]);
			n = nn / gcd(nn, nd);
			d = nd / gcd(nn, nd);
		}
		rep(i, m){
			printf("%d\n", (n/dist[i])*(velo[i]/d));
		}
	}
	return 0;
}