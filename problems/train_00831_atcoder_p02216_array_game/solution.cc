#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    istream& in(cin);
    ostream& out(cout);
    int n;
    ll s{},m=LLONG_MAX;
    in>>n;
    vector<ll> a(n);
    for(auto&i:a) in>>i,s+=i,m=min(m,i);
    if(n&1) return puts(s%2?"First":"Second"),0;
    if(m&1) return puts("First"),0;
    puts(s%2?"First":"Second");
}
