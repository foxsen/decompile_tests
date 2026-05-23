#include "bits/stdc++.h"
using namespace std;
signed main(){
    int n;
    cin >> n;
    long long x, sv = 0, sp = 0, sz = 0, min1 = 0, min2 = 0, min3 = 0, min4 = 0;
    for(int i = 1; i <= n; i++){
        cin >> x;
        sv+=x; sp+=x%2; sz+=!x;
        min4 = min(min4,
            (min3 = min(min3,
                (min2 = min(min2,
                    (min1 = min(min1,
                        sv-sp-2*sz
                    )) + 2*sz+2*sp-i
                )) - 2*sz-2*sp+i
            )) - sv+sp+2*sz
        );
    }
    cout << min4 + sv << endl;
}