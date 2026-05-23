#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int a, b, c, n;
    while(cin >> a >> b >> c >> n){
        vector<int> state(a + b + c, 2);
        vector<vector<int> > tests(n, vector<int>(4));
        rep(i, n) rep(j, 4) cin >> tests[i][j];
    
        rep(i,n){
            if(tests[i][3] == 1){
                rep(j, 3) state[tests[i][j]-1] = 1;
            }
        }
        rep(i,n){
            if(tests[i][3] == 0){
                int cnt = 0, fail;
                rep(j, 3){
                    if (state[tests[i][j]-1] == 1) cnt++;
                    else
                        fail = j;
                }
                if(cnt == 2){
                    state[tests[i][fail]-1] = 0;
                }
            }
        }
        rep(i, a+b+c){
            cout << state[i] << endl;
        }
    }

}
