#include <bits/stdc++.h>

using namespace std;

const int maxn = 3010,mod = 1e9 + 7;
int n,m,sum[maxn],R[maxn],f[maxn][maxn];
char s[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + s[i] - '0';
        R[i] = i;
    }
    R[n + 1] = n + 1;
    sum[n + 1] = sum[n];
    for (int i = 1; i <= m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        R[x] = max(R[x],y);
    }
    for (int i = 2; i <= n + 1; i++)
        R[i] = max(R[i],R[i - 1]);
    f[1][sum[R[1]]] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            if (!f[i][j])
                continue;
            int k = sum[R[i + 1]] - sum[R[i]];
            if (j)
                (f[i + 1][j - 1 + k] += f[i][j]) %= mod;
            if (i + j <= R[i])
                (f[i + 1][j + k] += f[i][j]) %= mod;
        }
    printf("%d\n",f[n + 1][0]);

    return 0;
}
