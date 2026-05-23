#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef pair<int, int> P;

int main(){
    int n;
    while(cin >> n && n > 0){
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        if(n == 2) {
            int p1, t1, p2, t2;
            cin >> p1 >> t1 >> p2 >> t2;
            cout << abs(p1 - p2) << endl;
            continue;
        }
        vector<int> p1;
        vector<int> p2;
        p2.reserve(n * n);
        vector<P> pv;
        REP(i, n) {
            int p, t;
            cin >> p >> t;
            if(t == 1){
                p1.push_back(p);
            }else{
                pv.push_back(P(p, t));
            }
        }

        sort(pv.begin(), pv.end());
        REP(i, pv.size() - 1) pv[i].second --;
        REP(i, pv.size() - 1) pv[i + 1].second --;
        REP(i, pv.size()){
            REP(_, pv[i].second){
                p2.push_back(pv[i].first);
            }
        }

        int n1 = p1.size();
        int n2 = p2.size();

        if(n1 > n2) {
            cout << -1 << endl;
            continue;
        }

        sort(p1.begin(), p1.end());
        sort(p2.begin(), p2.end());

        long long ans = *max_element(p2.begin(), p2.end()) - *min_element(p2.begin(), p2.end());
        // cout << ans << endl;
        // cout << "p1 : "; REP(i, p1.size()) cout << p1[i] << " "; cout << endl;
        // cout << "p2 : "; REP(i, p2.size()) cout << p2[i] << " "; cout << endl;

        vector<long long> dp(2 * n1, 0);
        int last_base2 = -1;

        for(int i1 = 0; i1 < n1; i1++){
            vector<long long> next(2 * n1, LLONG_MAX);

            int base2 = lower_bound(p2.begin(), p2.end(), p1[i1]) - p2.begin();

            for(int di = 0; di < 2 * n1; di++){
                int i2 = di - n1 + base2;
                if(i2 < 0) continue;
                if(i2 >= n2) break;

                if(i1 == 0) {
                    next[di] = abs(p1[i1] - p2[i2]);
                    continue;
                }

                int lastdi = di + (base2 - last_base2) - 1;
                if(lastdi < 0) continue;

                long long last = (lastdi < 2 * n1 ? dp[lastdi] : dp.back());
                if(last == LLONG_MAX) continue;

                next[di] = last + abs(p1[i1] - p2[i2]);
                // printf("i1 = %d i2 = %d di = %d base = %d lastdi = %d last = %lld next[%d] <- %lld + %lld = %lld\n", i1, i2, di, base2, lastdi, last, di, last, abs(p1[i1] - p2[i2]), next[di]);
            }

            for(int j = 1; j < 2 * n1; j++){
                next[j] = min(next[j], next[j - 1]);
            }

            last_base2 = base2;
            dp.swap(next);
        }

        cout << ans + (n1 != 0 ? dp.back() : 0) << endl;
    }

    return 0;
}