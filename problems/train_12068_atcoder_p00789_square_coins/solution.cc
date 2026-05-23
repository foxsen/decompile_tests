#include <iostream>
#include <cstring>

using namespace std;

int dp[310];

int main(){
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for(int i=1; i < 17; i++){
        for(int j=1; j < 300; j++){
            if(j < i*i) continue;
            dp[j] += dp[j-i*i];
        }
    }

    int n;
    while(cin >> n, n){
        cout << dp[n] << endl;
    }
}