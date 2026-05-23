#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 1000000000;

int main() {
    int H, W;
    while(cin >> H >> W, H | W) {
        int n = H * W;
        vector<vector<int>> A(n, vector<int>(n, INF));
        vector<int> heart;
        for(int i = 0; i < n; ++i) A[i][i] = 0;
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) {
            int h;
            cin >> h;
            if(h) heart.push_back(i * W + j);
            for(bool d: {false, true}) {
                int y = i + (d ? 1 : 0);
                int x = j + (d ? 0 : 1);
                if(y < 0 || H <= y) continue;
                if(x < 0 || W <= x) continue;
                A[i * W + j][y * W + x] = A[y * W + x][i * W + j] = 1;
            }
        }

        for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j)
            A[i][j] = min(A[i][j], A[i][k] + A[k][j]);

        vector<vector<int>> OPT(1 << heart.size(), vector<int>(n, INF));

        for(int i = 0; i < heart.size(); ++i) for(int q = 0; q < n; ++q)
            OPT[1 << i][q] = A[heart[i]][q];

        for(int S = 1; S < (1 << heart.size()); ++S) {
            if(!(S & (S - 1))) continue;

            for(int p = 0; p < n; ++p) for(int E = 1; E < S; ++E)
                if(E | S == S) 
                    OPT[S][p] = min(OPT[S][p], OPT[E][p] + OPT[S ^ E][p]);

            for(int p = 0; p < n; ++p) for(int q = 0; q < n; ++q)
                    OPT[S][p] = min(OPT[S][p], OPT[S][q] + A[q][p]);
        }

        int answer = INF;
        for(int S = 1; S < (1 << heart.size()); ++S) for(int q = 0; q < n; ++q)
            answer = min(answer, OPT[S][q] + OPT[((1 << heart.size()) - 1) ^ S][q]);

        cout << max(0, n - (answer + 1)) << endl;
    }
}