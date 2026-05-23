#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int64_t N;
    cin >> N;
    vector<int64_t> a(N);
    for(int i=0; i<N; i++) {
        cin >> a[i];
    }

    int64_t ans = 0;
    sort(a.rbegin(), a.rend());
    while(a[0] >= N) {
        int64_t cnt = a[0] / N;
        ans += cnt;
        a[0] -= cnt*N;
        for(int i=1; i<N; i++) {
            a[i] += cnt;
        }
        sort(a.rbegin(), a.rend());
    }

    cout << ans << endl;
    return 0;
}
