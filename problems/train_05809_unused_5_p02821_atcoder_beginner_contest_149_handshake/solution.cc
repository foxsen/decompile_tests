#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t N, M;
    cin >> N >> M;
    vector<int64_t> A(N), S(N+1);
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    for(int i=0; i<N; i++) S[i+1] = S[i] + A[i];

    // ok : ok以上がM回以上
    int64_t ok = 0, ng = 1e6;
    while(ng-ok>1){
        int64_t mid = (ok+ng)/2;
        int64_t num = 0;
        for(int i=0; i<N; i++){
            num += A.end() - lower_bound(A.begin(), A.end(), mid - A[i]);
        }
        (num >= M ? ok : ng) = mid;
    }
    int64_t ans = 0, num = 0;
    for(int i=0; i<N; i++){
        int pt = lower_bound(A.begin(), A.end(), ng - A[i]) - A.begin();
        num += N-pt;
        ans += S[N] - S[pt] + (N-pt)*A[i];
    }
    ans += ok*(M-num);
    cout << ans << endl;
    return 0;
}
