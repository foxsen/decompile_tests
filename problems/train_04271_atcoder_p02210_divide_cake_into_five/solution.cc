#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Y;
    cin >> N >> Y;
    vector<int64_t> A(2*N), S(2*N+1);
    for(int i=0; i<N; i++){
        cin >> A[i];
        A[i+N] = A[i];
    }
    for(int i=0; i<2*N; i++){
        S[i+1] = S[i] + A[i];
    }
    int64_t L = accumulate(A.begin(), A.end(), 0LL) / 10 - Y;
    int64_t ans = 0;
    for(int s=N; s>=0; s--){
        int t = s+N;
        int64_t dp[601][6] = {0};
        dp[s][0] = 1;
        for(int i=s; i<t; i++) for(int j=i+1; j<=t; j++) if(S[j] - S[i] >= L) for(int k=0; k<5; k++){
            if(k == 0 && j <= N) continue;
            dp[j][k+1] += dp[i][k];
        }
        ans += dp[t][5];
    }
    cout << ans << endl;
    return 0;
}

