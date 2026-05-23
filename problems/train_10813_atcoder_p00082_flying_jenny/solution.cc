#include <bits/stdc++.h>

using namespace std;

int main() {

    int p[8];
    int c[8] = {4, 1, 2, 1, 2, 1, 4, 1};

    int temp[10];
    int ans[10];

    while(cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> p[5] >> p[6] >> p[7]) {

        memset(ans, 0, sizeof(ans));
        ans[8] = -1;

        for(int i = 0; i < 8; ++i) {

            int digit = 10000000;
            memset(temp, 0, sizeof(temp));

            for(int j = 0; j < 8; ++j) {
                int pos = (i + j) % 8;
                if(p[j] >= c[pos]) {
                    temp[j] =  c[pos];
                } else {
                    temp[j] = p[j];
                }
                temp[8] += temp[j];
                temp[9] += c[pos] * digit;
                digit /= 10;

            }

            if(temp[8] > ans[8]) {
                for(int i = 0; i < 10; ++i) {
                    ans[i] = temp[i];
                }
            } else if(temp[8] == ans[8]) {
                if(temp[9] < ans[9]) {
                    for(int i = 0; i < 10; ++i) {
                        ans[i] = temp[i];
                    }
                }
            }

        }

        for(int i = 10000000; i >= 10; i /= 10) {
            cout << (ans[9] / i) << " ";
            ans[9] %= i;
        }
        cout << ans[9] << endl;

    }

}