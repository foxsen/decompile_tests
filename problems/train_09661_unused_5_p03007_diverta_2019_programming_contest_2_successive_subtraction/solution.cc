#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x: a) cin >> x;

    sort(a.begin(), a.end());

    long ma = a[n-1], mi = a[0];

    long r = ma - mi;
    for(int i=1; i<n-1; i++) {
        r += max(a[i], -a[i]);
    }
    cout << r << endl;

    for(int i=1; i<n-1; i++) {
        long aa = a[i];
        if(aa > 0) {
            cout << mi << ' ' << aa << endl;
            mi -= aa;
        } else {
            cout << ma << ' ' << aa << endl;
            ma -= aa;
        }
    }
    cout << ma << ' '<< mi << endl;
}
