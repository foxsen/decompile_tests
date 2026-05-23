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
#include <iterator>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > f(n, vector<int>(m));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> f[i][j];
        }
    }

    int d;
    cin >> d;
    vector<int> inCnt(n, 0);
    vector<vector<int> > edges(n);
    for(int i=0; i<d; ++i){
        int a, b;
        cin >> a >> b;
        -- a;
        -- b;
        edges[a].push_back(b);
        ++ inCnt[b];
    }

    vector<int> e(m);
    for(int i=0; i<m; ++i){
        cin >> e[i];
        -- e[i];
    }
    int r;
    cin >> r;
    vector<int> eThreshold(r);
    vector<vector<int> > eList(r, vector<int>(m));
    for(int i=0; i<r; ++i){
        cin >> eThreshold[i];
        for(int j=0; j<m; ++j){
            cin >> eList[i][j];
            -- eList[i][j];
        }
    }

    vector<vector<int> > permutation(1, vector<int>(m));
    for(int i=0; i<m; ++i)
        permutation[0][i] = i;
    for(;;){
        vector<int> v = permutation.back();
        if(!next_permutation(v.begin(), v.end()))
            break;
        permutation.push_back(v);
    }

    vector<priority_queue<pair<vector<int>, int> > > pq(permutation.size());
    for(int i=0; i<n; ++i){
        if(inCnt[i] != 0)
            continue;
        for(unsigned j=0; j<permutation.size(); ++j){
            vector<int> f2(m);
            for(int k=0; k<m; ++k)
                f2[k] = f[i][permutation[j][k]];
            pq[j].push(make_pair(f2, i));
        }
    }

    int eNext = 0;
    vector<bool> check(n, false);
    for(int i=0; i<n; ++i){
        if(eNext < r && eThreshold[eNext] == i){
            e = eList[eNext];
            ++ eNext;
        }

        int eIndex = find(permutation.begin(), permutation.end(), e) - permutation.begin();
        int curr;
        for(;;){
            curr = pq[eIndex].top().second;
            pq[eIndex].pop();
            if(!check[curr])
                break;
        }
        cout << (curr + 1) << endl;
        check[curr] = true;

        for(int next : edges[curr]){
            -- inCnt[next];
            if(inCnt[next] == 0){
                for(unsigned j=0; j<permutation.size(); ++j){
                    vector<int> f2(m);
                    for(int k=0; k<m; ++k)
                        f2[k] = f[next][permutation[j][k]];
                    pq[j].push(make_pair(f2, next));
                }
            }
        }
    }

    return 0;
}