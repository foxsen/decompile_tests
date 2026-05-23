#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define M 1000000007
#define read(arr) for(int i=0;i<n;i++) cin>>arr[i];
#define print(arr) for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
#define vl vector<ll>

bool sortcoll(vector<ll> &v1, vector<ll> &v2)
{
    return v1[1]>v2[1];
}

bool isPrime(ll n)
{
    if(n==1)
        return true;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        if(a==b)
            cout<<0<<" "<<0<<endl;
        else
        {
            ll x=abs(a-b);
            ll l=(min(a,b)/x)*x;
            ll u=(max(a,b)/x+1)*x;
            ll res=LLONG_MAX;
            for(ll i=l;i<=u;i+=x)
            {
                if(min(abs(i-a),abs(i-b))<res)
                    res=min(abs(i-a),abs(i-b));
            }
            cout<<x<<" "<<res<<endl;
        }
    }

}
