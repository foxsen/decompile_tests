#include <iostream>
#include <algorithm>

#define long long long

using namespace std;

long f(long x) 
{
    if (x <= 0) return 0;
    return min(x, 2 + f((x - 2) / 3) + (x - 2) % 3);
}

int main()
{
    long x;
    cin >> x;
    cout << f(x + 1) - 1 << '\n';
    return 0;
}
