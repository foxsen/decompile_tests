#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

const double INF = DBL_MAX / 1000;
const double EPS = 1.0e-10;

int L;
vector<double> a;

double calculateError(int x, int y)
{
    double vMax = 0.0;
    double vMin = 1.0;
    for(int i=x; i<=y; ++i){
        vMax = max(vMax, a[i]);
        vMin = min(vMin, a[i]);
    }

    double ret = 0.0;
    for(int i=x; i<=y; ++i){
        int j = (int)((a[i] - vMin) * (L - 1) / (vMax - vMin) + EPS);
        double q1 = vMin + j * (vMax - vMin) / (L - 1);
        double q2 = vMin + (j + 1) * (vMax - vMin) / (L - 1);

        double d = min(abs(q1 - a[i]), abs(q2 - a[i]));
        d = d * d;
        ret += d;
    }
    return ret;
}

int main()
{
    for(;;){
        int n, m;
        cin >> n >> m >> L;
        if(n == 0)
            return 0;

        L = 1 << L;

        a.resize(n);
        for(int i=0; i<n; ++i)
            cin >> a[i];

        vector<vector<double> > error(n, vector<double>(n));
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                error[i][j] = calculateError(i, j);
            }
        }

        vector<vector<double> > dp(n+1, vector<double>(m+1, INF));
        dp[0][0] = 0.0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                for(int k=i+1; k<n; ++k){
                    dp[k+1][j+1] = min(dp[k+1][j+1], dp[i][j] + error[i][k]);
                }
            }
        }

        printf("%.10f\n", dp[n][m]);
    }
}