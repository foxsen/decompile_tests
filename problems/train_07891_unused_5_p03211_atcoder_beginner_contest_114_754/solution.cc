#include<iostream>
#include<cmath>

using namespace std;
int main(void)
{
    long long s, n, mn = 1e9;
    cin >> s;
    for(;s>=100;s/=10)
    {
        n=s%1000;
        mn = min(mn, (long long)abs(753-n));
    }
    cout << mn;
    return 0;
}
