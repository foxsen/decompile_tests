#include <bits/stdc++.h>

using namespace std;

int SolveDaruma(const int n, const vector<int> &w) {
    vector<vector<int>> s(n, vector<int>(n));

    for (int l = 0; l + 1 < n; ++l)
        if (abs(w[l] - w[l + 1]) <= 1)
            s[l][l + 1] = 2;

    for (int i = 3; i <= n; ++i)
        for (int l = 0; l + i <= n; ++l) {
            const int r = l + i - 1;

            if (abs(w[l] - w[r]) <= 1 && s[l + 1][r - 1] == i - 2)
                s[l][r] = i;

            for (int m = l + 1; m <= r; ++m)
                s[l][r] = max(s[l][r], s[l][m - 1] + s[m][r]);
        }

    return s[0][n - 1];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;

    while (cin >> n, n) {
        vector<int> w(n);
        for (auto &x : w) cin >> x;

        cout << SolveDaruma(n, w) << '\n';
    }

    return 0;
}

