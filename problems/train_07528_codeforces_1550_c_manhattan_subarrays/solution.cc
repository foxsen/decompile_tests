#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;

bool zigorzag(int a, int b, int c) {
    return (a > b && b < c) || (a < b && b > c);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> foo(n);
        for (auto& el : foo)
            cin >> el;

        ll ans = n + (n - 1);

        for (int i = 0; i + 3 <= n; i++) {
            ans += zigorzag(foo[i], foo[i + 1], foo[i + 2]);
        }

        for (int i = 0; i + 4 <= n; i++) {
            ans += zigorzag(foo[i], foo[i + 1], foo[i + 2]) &&
                   zigorzag(foo[i], foo[i + 1], foo[i + 3]) &&
                   zigorzag(foo[i], foo[i + 2], foo[i + 3]) &&
                   zigorzag(foo[i + 1], foo[i + 2], foo[i + 3]);
        }
        cout << ans << "\n";
    }

    return 0;
}