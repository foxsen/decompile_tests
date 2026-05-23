#include<cstdio>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;

const int N = 110;

char a[N], b[N];
int f[N];

int main()
{
    int _;
    scanf("%d", &_);
    while(_ --)
    {
        int n, m;
        scanf("%d%d%s", &n, &m, a + 1);
        while(m --)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            int len = r - l + 1;
            for(int i = 1; i <= len; i ++)  b[i] = a[l + i - 1];
            
            memset(f, 0, sizeof f);
            f[0] = 1;
            for(int i = 1; i <= n; i ++)
                for(int j = min(i, len); j; j --)
                    if(a[i] == b[j])  f[j] += f[j - 1];
            if(f[len] == 1)  puts("NO");
            else  puts("YES");
        }
    }
    return 0;
}