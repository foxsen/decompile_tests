#ifndef __cplusplus
    cat << EOF
#endif
#include <bits/stdc++.h>
using namespace std;

#define rep(...) overload_rep(__VA_ARGS__, rep_1, rep_0)(__VA_ARGS__)
#define rep_0(i, end) for(int i = 0; i < (end); ++i)
#define rep_1(i, fr, ba) for(int i = (fr); i <= (ba); ++i)
#define overload_rep(arg0, arg1, arg2, name, ...) name
#define all(box) box.begin(), box.end()

template <class T, class U> inline bool chmax(T& lhs, const U& rhs) { if(lhs < rhs) { lhs = rhs; return 1; } return 0; }
template <class T, class U> inline bool chmin(T& lhs, const U& rhs) { if(lhs > rhs) { lhs = rhs; return 1; } return 0; }

int N, K;
int A[20];
bitset<1 << 20> dp;

int main() {

    cin >> N >> K;
    rep(i, N) cin >> A[i];

    int ans = N;
    rep(S, 1 << N) {
        int sum = 0;
        rep(i, N) if((1 << i) & S) sum += A[i];
        if(sum == K || dp[S] == 1) {
            dp[S] = 1;
            rep(i, N) dp[S | (1 << i)] = 1;
        } else {
            chmin(ans, N - __builtin_popcount(S));
        }
    }

    cout << ans << '\n';
    return 0;

}

