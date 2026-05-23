#include<bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(false);
#define Bye return 0
#define CodeTyper main
using ll = long long;

using namespace std;

const int SZ = 2e5+1, mod = 1e9 + 7;

void run_case() {
    ll n, x, t, res, dis; cin>>n>>x>>t;
    dis = min(t/x, n-1);
    cout<<(dis*(dis-1)/2 + (n-dis)*dis)<<endl;
}

int CodeTyper()
{
    IOS;
    int t; cin>>t;
    while(t--) run_case();
    Bye;
}

/*
    Think first, then Code. - CodeTyper
*/
