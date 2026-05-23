#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int DP[2100][2100];
long long int res[2100][2] = {};

int main(){
    string SS, S[2] = {"", ""}, hoge = " ";
    cin >> SS;
    int K;
    cin >> K;
    for(int i = 0; i < SS.size(); i++){
        if(SS[i] == 'L' || SS[i] == 'R'){
            hoge[0] = '0' + (SS[i] == 'R');
            S[0] += hoge;
        }else{
            hoge[0] = '0' + (SS[i] == 'U');
            S[1] += hoge;
        }
    }
    for(int n = 0; n < 2; n++){
        for(int p = 0; p < 2; p++){
            for(int i = 0; i < 2100; i++){
                for(int j = 0; j < 2100; j++){
                    DP[i][j] = -INF;
                }
            }
            DP[0][0] = 0;
            for(int i = 0; i < S[n].size(); i++){
                for(int j = 0; j <= K; j++){
                    if(S[n][i] == '0' + (p + j) % 2){
                        DP[i + 1][j] = max(DP[i + 1][j], DP[i][j] - 1);
                    }else{
                        DP[i + 1][j] = max(DP[i + 1][j], DP[i][j] + 1);
                    }
                    DP[i][j + 1] = max(DP[i][j + 1], DP[i][j]);
                }
            }
            for(int j = 0; j <= K; j++){
                DP[S[n].size()][j + 1] = max(DP[S[n].size()][j + 1], DP[S[n].size()][j]);
                res[j][n] = max(res[j][n], DP[S[n].size()][j]);
            }
        }
    }
    long long int ans = 0;
    for(int i = 0; i <= K; i++){
        ans = max(ans, res[i][0] + res[K - i][1]);
    }
    cout << ans << endl;
    return 0;
}
