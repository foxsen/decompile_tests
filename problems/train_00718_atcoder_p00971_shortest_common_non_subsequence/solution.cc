#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; (i) < (n); ++(i))
#define REP3(i,m,n) for (int i = (m); (i) < (n); ++(i))
#define REP_R(i,n) for (int i = (int)(n) - 1; (i) >= 0; --(i))
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
template <class T> inline void chmin(T & a, T const & b) { a = min(a, b); }

vector<array<int, 2> > make_table(string const & s) {
    int n = s.length();
    vector<array<int, 2> > next(n + 2);
    next[n][0] = n;
    next[n][1] = n;
    next[n + 1][0] = n;
    next[n + 1][1] = n;
    REP_R (i, n) {
        next[i] = next[i + 1];
        next[i][s[i] - '0'] = i;
    }
    return next;
}

string solve(string const & p, string const & q) {
    auto next_p = make_table(p);
    auto next_q = make_table(q);

    // run dp based on greedy
    vector<vector<int> > dp(p.size() + 2, vector<int>(q.size() + 2, INT_MAX));
    dp[0][0] = 0;
    REP (i, p.size() + 2) {
        REP (j, q.size() + 2) if (dp[i][j] != INT_MAX) {
            REP (c, 2) {
                chmin(dp[next_p[i][c] + 1][next_q[j][c] + 1], dp[i][j] + 1);
            }
        }
    }

    // propagate the flag
    vector<vector<bool> > pred(p.size() + 2, vector<bool>(q.size() + 2, false));
    pred[p.size() + 1][q.size() + 1] = true;
    REP_R (i, p.size() + 2) {
        REP_R (j, q.size() + 2) if (dp[i][j] != INT_MAX) {
            REP (c, 2) {
                int ni = next_p[i][c] + 1;
                int nj = next_q[j][c] + 1;
                if (pred[ni][nj] and dp[ni][nj] == dp[i][j] + 1) {
                    pred[i][j] = true;
                }
            }
        }
    }
    assert (pred[0][0]);

/*
    REP (i, p.size() + 2) {
        REP (j, q.size() + 2) {
            if (dp[i][j] == INT_MAX) {
                cerr << ". ";
            } else if (pred[i][j]) {
                cerr << dp[i][j] << " ";
            } else {
                cerr << "(" << dp[i][j] << ") ";
            }
        }
        cerr << endl;
    }
*/

    // reconstruct
    string s;
    for (int i = 0, j = 0; i <= p.size() or j <= q.size(); ) {
        int c = 0;
        while (c < 2 and not (pred[next_p[i][c] + 1][next_q[j][c] + 1] and dp[next_p[i][c] + 1][next_q[j][c] + 1] == dp[i][j] + 1)) ++ c;
        assert (c != 2);
        s += c + '0';
        i = next_p[i][c] + 1;
        j = next_q[j][c] + 1;
// cerr << i << ' ' << j << " (" << dp[i][j] << endl;
    }
    
    return s;
}

int main() {
    string p, q; cin >> p >> q;
    cout << solve(p, q) << endl;
    return 0;
}

