#include <bits/stdc++.h>
using namespace std;

#define     F       first
#define     S       second
typedef pair<int, int>  pi;
typedef long long       ll;
const ll big = 1e6 + 9;
ll GCD(ll a,ll b)
{
    if(!b)
        return a;
    return GCD(b, a % b);
}
ll LCM(ll a,ll b)
{
    return a*b/GCD(a,b);
}

int main()
{ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll t;
    cin >> t;
    while(t--)
    {
        string s, t;
        cin >> s >> t;
        ll n1 = s.size(), n2 = t.size();
        ll lcm = LCM(n1,n2);
        ll k1 = lcm/n1, k2 = lcm/n2;
        k1--,k2--;

        string s1 = s, t1 = t;
        while(k1--)
            s += s1;
        while(k2--)
            t += t1;
        if(s == t)
            cout << s << "\n";
        else
            cout << "-1\n";
    }

    return 0;
}