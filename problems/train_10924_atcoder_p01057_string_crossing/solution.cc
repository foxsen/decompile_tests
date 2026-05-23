#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
 
    int n, q;
    cin >> n >> q;
    vector<list<string> > v(n+1);
    for(int i=1; i<=n; ++i){
        string s;
        cin >> s;
        for(unsigned j=0; j<s.size(); j+=1000)
            v[i].push_back(s.substr(j, 1000));
    }
 
    while(--q >= 0){
        int type;
        cin >> type;
 
        if(type == 1){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
 
            auto it1 = v[a].begin();
            auto it2 = v[c].begin();
            while((int)it1->size() < b){
                b -= it1->size();
                ++ it1;
            }
            while((int)it2->size() < d){
                d -= it2->size();
                ++ it2;
            }
 
            string s = it2->substr(0, d-1) + it1->substr(b-1);
            string t = it1->substr(0, b-1) + it2->substr(d-1);
            *it1 = s;
            *it2 = t;
 
            list<string> x, y;
            x.splice(x.end(), v[a], v[a].begin(), it1);
            y.splice(y.end(), v[c], v[c].begin(), it2);
            x.splice(x.end(), v[c], v[c].begin(), v[c].end());
            y.splice(y.end(), v[a], v[a].begin(), v[a].end());
            v[a].swap(x);
            v[c].swap(y);
        }
        else{
            int a, b;
            char c;
            cin >> a >> b >> c;
 
            auto it = v[a].begin();
            while((int)it->size() < b){
                b -= it->size();
                ++ it;
            }
            (*it)[b-1] = c;
        }
    }
 
    for(int i=1; i<=n; ++i){
        for(const string& s : v[i])
            cout << s;
        cout << endl;
    }
 
    return 0;
}