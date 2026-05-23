#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
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

class Edge
{
public:
    int to, cost;
    Edge(int to, int cost){
        this->to = to;
        this->cost = cost;
    }
};

bool check(int pos, int t, const vector<pair<int, int> >& v)
{
    for(const auto& p : v){
        if(pos == p.first && t - p.second < 15)
            return false;
    }
    return true;
}

vector<pair<int, int> > normalize(int pos, int t, const vector<pair<int, int> >& v)
{
    vector<pair<int, int> > ans;
    for(const auto& p : v){
        if(pos == p.first){
            if(t - p.second < 15)
                ans.push_back(p);
        }
        else{
            if(t - p.second < 10)
                ans.push_back(p);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> d(n);
    for(int i=0; i<n; ++i)
        cin >> d[i];

    vector<vector<Edge> > edges(n);
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        -- a;
        -- b;
        edges[a].push_back(Edge(b, c));
        edges[b].push_back(Edge(a, c));
    }

    vector<pair<int, int> > empty;
    vector<vector<map<vector<pair<int, int> >, int> > > dp(r+1, vector<map<vector<pair<int, int> >, int> >(n));
    dp[0][0][empty] = 0;
    for(int t=0; t<r; ++t){
        for(int curr=0; curr<n; ++curr){
            for(const auto& p : dp[t][curr]){
                vector<pair<int, int> > v = p.first;
                int ball = p.second;
                if(check(curr, t, v)){
                    v.push_back(make_pair(curr, t));
                    ball += d[curr];
                }

                for(const Edge& e : edges[curr]){
                    int next = e.to;
                    int t2 = t + e.cost;
                    if(t2 <= r){
                        auto v2 = normalize(next, t2, v);
                        dp[t2][next][v2] = max(dp[t2][next][v2], ball);
                    }
                }

                int t2;
                for(unsigned i=0; i<v.size(); ++i){
                    if(v[i].first == curr)
                        t2 = v[i].second + 15;
                }
                if(t2 <= r){
                    auto v2 = normalize(curr, t2, v);
                    dp[t2][curr][v2] = max(dp[t2][curr][v2], ball);
                }
            }
        }
    }
    
    int ans = 0;
    for(int t=0; t<=r; ++t){
        for(const auto& p : dp[t][n-1]){
            ans = max(ans, p.second);
        }
    }
    cout << ans << endl;

    return 0;
}