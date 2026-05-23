#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7, M = 1e9+7;
int ll[N];
long long a[N], dp[N], sum[N];

long long getsum(int l, int r) {
    if (r < l)  return 0;
    if (l == 0) return sum[r];
    return sum[r] - sum[l-1];
}

void zero() {
    cout<<0<<endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    long long x, y;
    cin>>x>>y;

    if (x > y)  swap(x, y);

    for (int i=1; i<=n; i++)    cin>>a[i];

    for (int i=1; i<=n; i++) {
        if (i == 1 || a[i-1] > a[i]-x) ll[i] = i;
        else    ll[i] = ll[i-1];
    }

    for (int i=3; i<=n; i++)
        if (a[i] - a[i-2] < x)  zero();

    dp[0] = sum[0] = 1;
    int ptr = 0;
    for (int i=1; i<=n; i++) {
        while (a[ptr+1] <= a[i] - y)   ptr++;

        int en = ptr, st = max(0, ll[i-1]-1);


        dp[i] = getsum(st, en)%M;
        sum[i] = (dp[i] + sum[i-1])%M;
//        cout<<i<<" "<<a[i]<<" --> "<<st<<" "<<en<<" --> "<<dp[i]<<" "<<sum[i]<<endl;

    }

    long long ans = getsum(ll[n]-1, n);
    cout<<(ans%M+M)%M<<endl;
}
