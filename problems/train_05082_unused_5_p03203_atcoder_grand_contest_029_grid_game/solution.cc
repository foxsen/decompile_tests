#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ff first
#define ss second
vector<pair<int,int>> v;
signed main(){
    int h, n, x = 0;
    cin >> h >> n >> n;
    v.resize(n);
    for(auto& i: v)
        cin >> i.ss >> i.ff;
    sort(v.begin(),v.end());
    for(auto p: v){
        if(p.ss > p.ff+x)h = min(h, p.ss-1);
        if(p.ss == p.ff+x)x++;
    }
    cout << h << endl;
}
