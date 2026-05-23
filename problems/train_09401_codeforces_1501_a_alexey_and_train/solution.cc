#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc-- > 0) {
        int n;
        cin >> n;

        vector<int> a(n+1), b(n+1), t(n+1);

        for(int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        for(int i = 1; i <= n; i++) { cin >> t[i]; }

        int cur = 0, arrive = 0;

        for(int i = 1; i <= n; i++) {
            arrive = cur + (a[i] - b[i - 1] + t[i]);

            if(i != n) {
                int wait = (b[i] - a[i] + 1) / 2;
                cur = max(arrive + wait, b[i]);
            }
        }

        cout << arrive << endl;
    }
}