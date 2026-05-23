#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> u,v;
int main(){
    int i,n; cin >> n;
    for(i=0;i<n;i++){
        long long x,y; cin >> x >> y;
        u.push_back(x + y),v.push_back(x - y);
    }
    sort(u.begin(),u.end()); sort(v.begin(),v.end());
    long long ans = max(u[n - 1] - u[0],v[n - 1] - v[0]);
    cout << ans << endl;
}