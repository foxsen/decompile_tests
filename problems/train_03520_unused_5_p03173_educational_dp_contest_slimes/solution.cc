#include <iostream>
using namespace std;
int n;
long long a[404], b[404], d[404][404];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = b[i - 1] + a[i];
    for (int i = 1; i < n; i++) for (int j = 1; j + i <= n; j++) {
        d[j][j + i] = 1e18;
        for (int k = j; k < j + i; k++) d[j][j + i] = min(d[j][j + i], d[j][k] + d[k + 1][j + i]);
        d[j][j + i] += b[j + i] - b[j - 1];
    }
    cout << d[1][n] << '\n';
}
