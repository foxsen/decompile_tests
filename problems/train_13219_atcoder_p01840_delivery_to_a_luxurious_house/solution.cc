#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,t;
    cin>>n>>m>>t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int ans=a.front()-m;
    for (int i = 1; i < n; ++i) {
        if(a[i]-a[i-1]>2*m)ans+=(a[i]-a[i-1])-2*m;
    }
    if(t-a.back()>m)ans+=t-a.back()-m;
    cout<<ans<<endl;
    return 0;
}
