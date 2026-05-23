#include <bits/stdc++.h>
using namespace std;

long long solve(long long l, int n, vector<long long> &x, vector<long long> &y) {
    long long ret = 0;
    vector<long long> cumx(n+1, 0), cumy(n+1, 0);
    for (int i = 0; i < n; i++) {
        cumx[i+1] = cumx[i] + x[i];
        cumy[i+1] = cumy[i] + y[i];
    }
    for (int i = 0; i < n; i++) {
        // x[i] で向きを変える
        long long tmp = 0;
        int remain = n-i;
        int remx = (remain+1) / 2;
        int remy = remain - remx;
        tmp += (cumx[remx+i] - cumx[i]) * 2;
        tmp += (cumy[remy]) * 2;
        if (remain & 1) tmp -= x[remx+i-1];
        else tmp -= y[remy-1];
        //cout << i << " " << tmp << " rem:" << remx << " " << remy << endl;
        ret = max(ret, tmp);
    }
    return ret;
}

int main() {
    long long l; int n; cin >> l >> n;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) y[i] = l - x[i];
    reverse(y.begin(), y.end());
    auto ans1 = solve(l, n, x, y);
    auto ans2 = solve(l, n, y, x);
    cout << max(ans1, ans2) << endl;
    return 0;
}