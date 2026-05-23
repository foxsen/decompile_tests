#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n;
    cin >> n;
    vector<int> x(n+1);
    vector<int> y(n+1);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    sort(x.rbegin(), x.rend());
    sort(y.begin(), y.end());
    ll ans = 0;
    for(int i = 0; i < n+1; i++)
    {
        if(x[i] - y[i] > 0)
        {
            ans += 2*(x[i] - y[i]);
        }
    }
    cout << ans << endl;
}
