#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

#define FOR(i,b,n) for(int i=b;i<n;i++)
#define RFOR(i,b,n) for(int i=n-1;i>=b;i--)
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define NCLR(mat) memset(mat, -1, sizeof(mat))

using namespace std;

static const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> paii;

int dp[2][1000][1000];//0...head east 1...head north

int solve(int w, int h)
{
	CLR(dp);
	
	FOR(k, 0, h+w+1)
	{
		dp[0][k][1] = 1;
		dp[1][k][1] = 1;
		dp[0][1][k] = 1;
		dp[1][1][k] = 1;
	}

	FOR(j, 2, h+1)
		FOR(i, 2, w+1)
		{
			dp[0][j][i] = (dp[0][j][i-1] + dp[1][j-2][i])%100000;
			dp[1][j][i] = (dp[1][j-1][i] + dp[0][j][i-2])%100000;
		}
		
	return (dp[0][h][w-1] + dp[1][h-1][w])%100000;
}

int main()
{
	int w, h;
	
	while(cin >> w >> h, (w||h))
	{
		cout << solve(w, h) << endl;
	}

	return 0;
}