#include <bits/stdc++.h>
using namespace std;

using Pi = pair < int, int >;
using IPi = pair < int , Pi >;

constexpr int INF = (1 << 30) - 1;

void chmin(int &a, int b) { a = min(a, b); }

int main()
{
        int N;
        int dp[1005][20];
        string S[1005];
        priority_queue < IPi, vector < IPi > , greater < IPi > > pq;

        fill_n(*dp, 1005 * 20, INF);
        cin >> N;
        for ( int i = 0; i < N; i++ ) {
                cin >> S[i];
                dp[i][0] = 0;
                pq.emplace(0, Pi(i, 0));
        }
        
        while ( !pq.empty() ) {
                IPi dat = pq.top(); pq.pop();
                int cost = dat.first, node = dat.second.first, pos = dat.second.second;
                int nodesize = S[node].size();
                int remainsize = nodesize - pos;
                for ( int i = 0; i < N; i++ ) {
                        if ( i == node && pos == 0 ) continue;
                        int len = S[i].size();
                        if ( len > remainsize ) {
                                if ( S[node].substr(pos, remainsize) == S[i].substr(0, remainsize) ) {
                                        int ncost = cost + remainsize;
                                        if ( dp[i][remainsize] > ncost ) {
                                                chmin(dp[i][remainsize], ncost);
                                                pq.emplace(ncost, Pi(i, remainsize));
                                        }
                                }
                        } else if ( S[node].substr(pos, len) == S[i]) {
                                int ncost = cost + len;
                                if ( dp[node][pos + len] > ncost ) {
                                        chmin(dp[node][pos + len], ncost);
                                        if ( len < remainsize ) pq.emplace(ncost, Pi(node, pos + len));
                                }
                        }
                }
        }

        int minv = INF;

        for ( int i = 0; i < N; i++ ) {
                minv = min(minv, dp[i][S[i].size()]);
        }

        if ( minv == INF ) cout << 0 << endl;
        else cout << minv << endl;

        return ( 0 );
}

