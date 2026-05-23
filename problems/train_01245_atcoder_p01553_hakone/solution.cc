#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=1e9+7;
int main()
{
    int n; cin>>n;
    string s;
    for(int i=0; i<n; i++){
        char c; cin>>c;
        if(c!='-') s+=c;
    }
    n=s.size();
    ll dp[202][202]={};
    dp[0][0]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(s[i]=='U'){
                (dp[i+1][j]+=j*dp[i][j])%=MOD;
                (dp[i+1][j+1]+=dp[i][j])%=MOD;
            }else{
                (dp[i+1][j]+=j*dp[i][j])%=MOD;
                if(j) (dp[i+1][j-1]+=j*j*dp[i][j])%=MOD;
            }
        }
    }
    cout<<dp[n][0]<<endl;
    return 0;
}
