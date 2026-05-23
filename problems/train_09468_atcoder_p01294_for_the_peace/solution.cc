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
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    for(;;){
        int n, d;
        cin >> n >> d;
        if(n == 0 && d == 0)
            return 0;

        vector<stack<int> > q(n);
        vector<int> sum(n, 0);
        for(int i=0; i<n; ++i){
            int m;
            cin >> m;
            while(--m >= 0){
                int a;
                cin >> a;
                q[i].push(a);
                sum[i] += a;
            }
        }

        multiset<int> ms;
        for(int i=0; i<n; ++i)
            ms.insert(sum[i]);

        bool ng;
        while(*ms.rbegin() != 0){
            ng = true;
            for(int i=0; i<n; ++i){
                if(sum[i] == 0)
                    continue;

                ms.erase(ms.find(sum[i]));
                int x = sum[i] - q[i].top();
                if(abs(*ms.begin() - x) <= d && abs(*ms.rbegin() - x) <= d){
                    q[i].pop();
                    sum[i] = x;
                    ng = false;
                }
                ms.insert(sum[i]);
            }
            if(ng)
                break;
        }

        if(ng)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}