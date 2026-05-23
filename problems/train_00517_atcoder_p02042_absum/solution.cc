#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;




int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    priority_queue<ll> Q;
    priority_queue<ll,vector<ll>,greater<ll>> Q2;
    ll ans=0;
    for(ll i=0;i<n;i++){cin>>a[i]; ans+=abs(a[i]-i); Q.push(min(a[i],i)); Q2.push(max(a[i],i));}
    while(m--){
        ans+=max((Q.top()-Q2.top())<<1,0LL);
        Q.pop(); Q2.pop();
    }
    cout<<ans<<endl;
    
    
    return 0;
}

