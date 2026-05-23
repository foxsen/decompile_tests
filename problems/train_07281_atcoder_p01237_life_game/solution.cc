#include <bits/stdc++.h>
//#include <unordered_map>
#define N 111
#define ID(x, y) (pre[(x)-1]+(y-1))
#define CHECK(x, y) ((x)>0 && (x)<= 2 * n - 1 && (y)>0 && (y)<=(linelimit))
using namespace std;
typedef long long LL;
LL n, mod, m, l;
LL a[N][N], b[N][N], c[N][N], mat[N][N], pre[N];
void mul(LL A[N][N],LL B[N][N],LL t[N][N],LL n,LL m,LL l)
{
    LL tmp[N][N];
    for(LL i=0;i<n;i++)
        for(LL j=0;j<l;j++){
            tmp[i][j]=0;
            for(LL k=0;k<m;k++)
                tmp[i][j]=(tmp[i][j]+A[i][k]*B[k][j]%mod)%mod;
        }
    for(LL i=0;i<n;i++)
        for(LL j=0;j<l;j++)
            t[i][j]=tmp[i][j];
}
void expo(LL p[N][N],LL e[N][N],LL k,LL n)
{
    if(k!=1){
        for(LL i = 0; i < n; ++i)
            for(LL j = 0; j < n; ++j)
                e[i][j] = (i == j);
        while(k){
            if(k&1)
                mul(e,p,e,n,n,n);
            mul(p,p,p,n,n,n);
            k>>=1;
        }
    }else {
        for(LL i=0;i<n;i++)
            for(LL j=0;j<n;j++)
                e[i][j]=p[i][j];
    }
}
void addOneP(LL idx, LL x, LL y, LL linelimit)
{
    if(CHECK(x, y)) b[ID(x, y)][idx] = 1;
}
int main()
{
    LL cas = 1;
    while(~scanf("%lld%lld%lld", &n, &mod, &l) && (n || mod || l))
    {
        m = n;
        LL add = 1;
        LL num = 0;
        pre[0] = 0;
        for(LL i=1; i <= 2 * n -1; i++){
            pre[i] = m + pre[i-1];
            for(LL j=1;j<=m;j++)
                scanf("%lld", &mat[i][j]), a[0][num++] = mat[i][j]%mod;
            if(i == n) add = -1;
            m += add;
        }
        memset(b, 0, sizeof(b));
        m = n, add = 1;
        for(LL i=1; i <= 2 * n -1; i++){
            for(LL j=1;j<=m;j++)
            {
                addOneP(ID(i, j), i, j, m);
                addOneP(ID(i, j), i, j - 1, m);
                addOneP(ID(i, j), i, j + 1, m);
                addOneP(ID(i, j), i - 1, j, m - add);
                addOneP(ID(i, j), i + 1, j, m + (i < n ? 1 : -1));
                if(i < n) addOneP(ID(i, j), i - 1, j - 1, m - 1), addOneP(ID(i, j), i + 1, j + 1, m + 1);
                if(i == n) addOneP(ID(i, j), i - 1, j - 1, m - 1), addOneP(ID(i, j), i + 1, j - 1, m - 1);
                if(i > n) addOneP(ID(i, j), i - 1, j + 1, m + 1), addOneP(ID(i, j), i + 1, j - 1, m - 1);
            }
            if(i == n) add = -1;
            m += add;
        }
        expo(b, c, l, num);
        mul(a, c, b, 1, num, num);
        LL ans = 0;
        for(LL i=0;i<num;i++)
            ans += b[0][i];
        printf("Case %lld: %lld\n", cas++, ans);
    }
    return 0;
}