#include <iostream>

using namespace std;

int main(){
    int a[4] = {10,50,100,500};
    int n;
    bool flag = true;
    while(cin >> n, n){
        int coin[4];
        int mcoin[4];

        cin >> coin[0] >> coin[1] >> coin[2] >> coin[3];

        n = coin[0] * 10 + coin[1] * 50 + coin[2] * 100 + coin[3] * 500 - n;
        for(int i = 3; i >= 0; i--){
            mcoin[i] = n / a[i];
            n -= mcoin[i] * a[i];
        }

        if(flag) flag = false;
        else cout << endl;
        for(int i = 0; i < 4; i++){
            if(coin[i] > mcoin[i]) cout << a[i] << ' ' << coin[i] - mcoin[i] << endl;
        }
    }
}
