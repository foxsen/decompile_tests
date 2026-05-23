#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
const long long M = 1000000007;

int n, k;

long long C[N][N];
void pre()
{
    for (int i = 0; i < N; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }
}

int main()
{
    pre();
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        cout << (C[k - 1][i - 1] * C[n - k + 1][i]) % M << endl;
    }
    return 0;
}
