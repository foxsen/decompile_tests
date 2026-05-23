#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
int H, W;
bool field[105][105];
string S[105];
bool reach[105][105];


int main() {
    cin >> H >> W;
    for(int h = 0; h < H; h++) {
        cin >> S[h];
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if((h&1) & (w & 1)) continue;
            if(h % 2 == 0 and w % 2 == 0) {
                if((h + w) % 4 == 0) {
                    if(S[h][w] == '6') field[h][w] = true;
                } else {
                    if(S[h][w] == '1') field[h][w] = true;
                }
            } else {
                if(h % 4 == 1) {
                    if(S[h][w] == '2') field[h][w] = true;
                }
                if(h % 4 == 3) {
                    if(S[h][w] == '5') field[h][w] = true;
                }
                if(w % 4 == 1) {
                    if(S[h][w] == '3') field[h][w] = true;
                }
                if(w % 4 == 3) {
                    if(S[h][w] == '4') field[h][w] = true;
                }
            }
        }
    }
    reach[0][0] = true;
    queue<i_i> que;
    que.push({0, 0});
    int dh[4] = {1, -1, 0, 0};
    int dw[4] = {0, 0, 1, -1};
    while(!que.empty()) {
        auto now = que.front();
        que.pop();
        int nowh = now.first;
        int noww = now.second;
        for(int i = 0; i < 4; i++) {
            int newh = nowh + dh[i];
            int neww = noww + dw[i];
            if(newh < 0 or newh >= H) continue;
            if(neww < 0 or neww >= W) continue;
            if(!field[newh][neww]) continue;
            if(reach[newh][neww]) continue;
            que.push({newh, neww});
            reach[newh][neww] = true;
        }
    }
    if(reach[H-1][W-1]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
