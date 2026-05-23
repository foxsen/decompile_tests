#include <iostream>
#include <algorithm>
#define DAY_LENGTH 86400
#define FOUR_TO_SEVEN 10800
using namespace std;

bool check(int k, int ts[], int n) {
    for (int i = 0; i <= 2 * n - k; i++) {
        if (ts[k - 1 + i] - ts[i] <= FOUR_TO_SEVEN)
            return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int ts[n << 1], t = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ts[i] = (t + a) % DAY_LENGTH;
        t = (ts[i] + b) % DAY_LENGTH;
    }
    sort(ts, ts + n);
    for (int i = 0; i < n; i++) {
        ts[i + n] = ts[i] + DAY_LENGTH;
    }

    int lb = 0, ub = n + 1, ans = 0;
    for (int mid = (lb + ub) / 2; ub - lb > 1; mid = (lb + ub) / 2) {
        if (check(mid, ts, n)) {
            ans = mid;
            lb = mid;
        } else {
            ub = mid;
        }
    }
    cout << ans << endl;
    return 0;
}
