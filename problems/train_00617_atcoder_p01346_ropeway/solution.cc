#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int,int> pint;

#define DE 1
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define ALL(s) (s).begin(),(s).end()
#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define EACH(i,s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define COUT(x) cout<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl

template<class T1, class T2> ostream& operator<<(ostream &s, pair<T1,T2> P){return s<<'<'<<P.first<<", "<<P.second<<'>';}
template<class T> ostream& operator<<(ostream &s, vector<T> P) {s<<"{ ";for(int i=0;i<P.size();++i){if(i>0)s<<", ";s<<P[i];}return s<<" }"<<endl;}
template<class T1, class T2> ostream& operator<<(ostream &s, map<T1,T2> P) {s<<"{ ";for(__typeof__(P.begin()) it=P.begin();it!=P.end();++it){if(it!=P.begin())s<<", ";s<<'<'<<it->first<<"->"<<it->second<<'>';}return s<<" }"<<endl;}



ll N, L, M, R;
ll m[105];

int dp[105][20100];

int main() {
    //freopen( "/Users/macuser/Documents/Programming/Contest/input.in", "r", stdin );
    
    while (cin >> N >> L >> M >> R) {
        for (int i = 0; i < N; ++i) cin >> m[i];
        memset(dp, 0, sizeof(dp));
        R *= 2;
        M *= 2;
        
        dp[0][0] = 1;
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= M; ++j) {
                //cout << i << ", " << j << " : " << dp[i][j] << endl;
                
                if (dp[i][j] <= 0) continue;
                
                ll l1 = max(0LL, j + m[i]*R);
                ll r1 = min(M, j + m[i]*L) + 1;
                ll l2, r2;
                if (j - m[i]*L >= 0) {l2 = j - m[i]*L; r2 = min(M, j - m[i]*R) + 1;}
                else if (j - m[i]*R >= 0) {l2 = 0; r2 = min(M, max(abs(j - m[i]*L), abs(j - m[i]*R))) + 1;}
                else {l2 = abs(j - m[i]*R); r2 = min(M, abs(j - m[i]*L)) + 1;}
                
                if (l1 <= r1) {
                    dp[i+1][l1]++; dp[i+1][r1]--;
                }
                if (l2 <= r2) {
                    dp[i+1][l2]++; dp[i+1][r2]--;
                }
            }
            for (int j = 0; j <= M; ++j) {
                dp[i+1][j+1] += dp[i+1][j];
            }
        }
        
        bool exist = false;
        for (int i = 0; i <= M; ++i) {
            if (dp[N][i] > 0) {exist = true; break;}
        }
        
        if (exist) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
