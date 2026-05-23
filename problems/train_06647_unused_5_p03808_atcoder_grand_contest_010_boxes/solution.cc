#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<long> a(n);
    long s=0;
    for(auto& e: a) { cin>>e; s+=e; }

    auto m=n*(n+1L)/2;
    if (s%m>0) return cout<<"NO"<<endl, 0;

    int k=s/m;
    int t=0;
    for(int i=0; i<n; ++i) {
        auto e=a[(i+1)%n]-a[i]-k;
        if (e%n!=0 or e>0) return cout<<"NO"<<endl, 0;
        t+=-e/n;
    }
    cout<<(t==k ? "YES" : "NO")<<endl;
}
