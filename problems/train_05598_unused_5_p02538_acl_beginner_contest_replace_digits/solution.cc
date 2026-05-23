#include<bits/stdc++.h>
#define ll long long
#define mxn 200005
#define mod 998244353ll
using namespace std;
ll p10[mxn], p11[mxn], lazy[4*mxn], seg[4*mxn];
int N;
void propagate(int n, int s, int e)
{
    lazy[n*2]= lazy[n];
    lazy[n*2 +1]= lazy[n];
    int mid= (s+e)/2;
    seg[n*2]= (((p11[mid-s+1]*lazy[n])%mod)*p10[N-mid+1])%mod;
    seg[n*2 +1]= (((p11[e-mid]*lazy[n])%mod)*p10[N-e+1])%mod;
    lazy[n]= 0;
    return;
}
void update(int n, int s, int e, int l, int r, int d)
{
    if(s>=l && e<=r)
    {
        lazy[n]= d;
        seg[n]= (((p11[e-s+1]*d)%mod)*p10[N-e+1])%mod;
        return;
    }
    if(s>r || e<l)return;
    if(lazy[n])propagate(n, s, e);
    int mid= (s+e)/2;
    update(n*2, s, mid, l, r, d);
    update(n*2 +1, mid+1, e, l, r, d);
    seg[n]= (seg[n*2]+seg[n*2 +1])%mod;
    return;
}
int main()
{
    p10[1]= 1;
    p11[1]= 1;
    for(int i=2; i<mxn-2; i++)
    p10[i]= (p10[i-1]*10)%mod,
    p11[i]= (p11[i-1]+p10[i])%mod;
    int n, q;
    scanf("%d %d", &n, &q);
    N= n;
    for(int i=1; i<=n; i++)
    update(1, 1, N, i, i, 1);
    while(q--)
    {
        int l, r, d;
        scanf("%d %d %d", &l, &r, &d);
        update(1, 1, N, l, r, d);
        printf("%lld\n", seg[1]);
    }
    return 0;
}
