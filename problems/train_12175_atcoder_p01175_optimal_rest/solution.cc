#include <cstdio>
#include <iostream>
#include <sstream>
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

map<string, int> rest;

int getRest(const string& s)
{
    int n = s.size();
    int i = 0;
    int t = 0;
    while(i < n){
        int j = i+1;
        while(j < n && s[j] != 'R')
            ++ j;
        t += rest[s.substr(i, j-i)];
        i = j;
    }
    return t;
}

int main()
{
    for(int i=1; i<=64; i*=2){
        int len = 64 / i;
        string s = "R";
        if(i >= 10)
            s += i / 10 + '0';
        s += i % 10 + '0';
        rest[s] = len;

        for(int j=i*2; j<=64; j*=2){
            len += 64 / j;
            s += '.';
            rest[s] = len;
        }
    }

    vector<string> dp(2001, "");
    for(int i=0; i<=2000; ++i){
        for(map<string, int>::iterator it=rest.begin(); it!=rest.end(); ++it){
            int j = i + it->second;
            if(j > 2000)
                continue;

            string s = dp[i] + it->first;
            if(dp[j] == "" || s.size() < dp[j].size() || (s.size() == dp[j].size() && s < dp[j]))
                dp[j] = s;
        }
    }

    int d;
    cin >> d;

    while(--d >= 0){
        string s;
        cin >> s;

        int t = getRest(s);
        if(t <= 2000){
            cout << dp[t] << endl;
            continue;
        }

        string ret = dp[1952+t%32].substr(0, 20);
        while(ret[ret.size()-1] != 'R')
            ret = ret.substr(0, ret.size()-1);
        ret = ret.substr(0, ret.size()-1);

        t -= getRest(ret);
        while(t > 2000){
            ret += "R1.";
            t -= 64 + 32;
        }
        ret += dp[t];
        cout << ret << endl;
    }

    return 0;
}