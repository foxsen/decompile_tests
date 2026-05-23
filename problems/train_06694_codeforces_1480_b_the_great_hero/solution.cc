#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll A, B;
        int n;
        cin >> A >> B >> n;
        vector<ll> a(n), b(n);
        ll mx = 0;
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
            mx = max(mx, a[j]);
        }
        for (int j = 0; j < n; ++j)
            cin >> b[j];
        for (int j = 0; j < n; ++j)
            B -= a[j] * ((b[j] + A - 1) / A);
        if (B + mx > 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
