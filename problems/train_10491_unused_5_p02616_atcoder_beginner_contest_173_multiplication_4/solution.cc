#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll A[300001];
int main()
{
    ll n,k;
    cin>>n>>k;

    for(int i=0; i<n; i++)
        cin>>A[i];
    sort(A,A+n);
    ll ans=1,sign=1;
    int l=0,r=n-1;
    if(k%2)
    {
        ans=A[r--];
        --k;
        if(ans<0)
            sign=0;
    }
    while(k)
    {
        ll x=A[l]*A[l+1],y=A[r]*A[r-1];
        if(sign==1)
        {
            if(x>y)
            {
                ans=x%mod*ans%mod;
                l+=2;
            }
            else
            {
                ans=y%mod*ans%mod;
                r-=2;
            }
        }
        else
        {
            if(x<y)
            {
                ans=x%mod*ans%mod;
                l+=2;
            }
            else
            {
                ans=y%mod*ans%mod;
                r-=2;
            }
        }
        k-=2;
    }
    cout<<(ans+mod)%mod<<endl;
    return 0;
}
