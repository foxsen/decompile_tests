#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//ここから編集する
class Solve {
public:
    int H, N;
    vector<vector<vector<char>>> init;

//    vector<vector<int>> drop;
    vector<vector<vector<vector<char>>>> drop;

    int run(vector<vector<vector<vector<char>>>> &block) {
        auto state = init;
        int ret = 0;

        for (int i = 0; i < block.size(); ++i) {
            {
                bool flag = true;
                for (int l = 0; l < 2; ++l) {
                    for (int c = 0; c < 2; ++c) {
                        if (block[i][0][l][c] == '#') flag = false;
                    }
                }
                if (flag) {
                    for (int l = 0; l < 2; ++l) {
                        for (int c = 0; c < 2; ++c) {
                            if (block[i][1][l][c] == '#') {
                                block[i][0][l][c] = '#';
                                block[i][1][l][c] = '.';
                            }
                        }
                    }
                }
            }

            //設置
            int sh = H + 2 * i;
            for (int dh = 0; dh < 2; ++dh) {
                for (int x = 0; x < 2; ++x) {
                    for (int y = 0; y < 2; ++y) {
                        state[sh + dh][x][y] = block[i][dh][x][y];
                    }
                }
            }

            //落とす
            int h = sh;
            // state[h]が空ならhを+1する しません

            auto down = [&]() {
                for (int l = 0; l < 2; ++l) {
                    for (int c = 0; c < 2; ++c) {
                        if (block[i][0][l][c] == '#') {
                            state[h - 1][l][c] = state[h][l][c];
                            state[h][l][c] = '.';
                        }
                    }
                }
                for (int l = 0; l < 2; ++l) {
                    for (int c = 0; c < 2; ++c) {
                        if (block[i][1][l][c] == '#') {
                            state[h][l][c] = state[h + 1][l][c];
                            state[h + 1][l][c] = '.';
                        }
                    }
                }
                h--;
            };
            while (true) {
                if (h == 0) break;
                //hのしたにブロックがあるなら終了
                bool blockflag = false;
//                for (int l = 0; l < 2; ++l) {
//                    for (int c = 0; c < 2; ++c) {
//                        if (state[h][l][c] == '#' && state[h - 1][l][c] == '#') blockflag = true;
//                    }
//                }
                for (int dh = 0; dh < 2; ++dh) {
                    for (int l = 0; l < 2; ++l) {
                        for (int c = 0; c < 2; ++c) {
                            if (dh == 0) {
                                if (block[i][dh][l][c] == '#' && state[h + dh - 1][l][c] == '#') {
                                    blockflag = true;
                                }
                            } else {
                                if (block[i][dh][l][c] == '#' &&
                                    block[i][dh - 1][l][c] != '#' &&
                                    state[h + dh - 1][l][c] == '#') {
                                    blockflag = true;
                                }
                            }
                        }
                    }
                }


                if (blockflag) break;
                down();
            }

            //消せるやつがあるなら消す

            auto deletable = [&]() {
                for (int hh = 0; hh < state.size(); ++hh) {
                    bool flag = true;
                    for (int l = 0; l < 2; ++l) {
                        for (int c = 0; c < 2; ++c) {
                            if (state[hh][l][c] == '.') flag = false;
                        }
                    }
                    if (flag) return hh;
                }
                return -1;
            };

            while (true) {
                int hh = deletable();
                if (hh == -1) break;
                ret++;
                for (int l = 0; l < 2; ++l) {
                    for (int c = 0; c < 2; ++c) {
                        state[hh][l][c] = '.';
                    }
                }

                for (; hh + 1 < state.size(); ++hh) {
                    for (int l = 0; l < 2; ++l) {
                        for (int c = 0; c < 2; ++c) {
                            state[hh][l][c] = state[hh + 1][l][c];
                            state[hh + 1][l][c] = '.';
                        }
                    }
                }
            }
        }
        return ret;
    }

    int getketa(int val, int p, int d = 3) {
        val /= (int) round(pow(d, p));
        return val % d;
    }

    bool solve() {
        cin >> H >> N;
        if (H == 0) return false;
        init.resize(H + 6, vector<vector<char>>(2, vector<char>(2, '.')));
//        drop.resize(N, vector<int>(2, 0));
        drop.resize(N, vector<vector<vector<char>>>(2, vector<vector<char>>(2, vector<char>(2, '.'))));

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    cin >> init[i][j][k];
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    for (int c = 0; c < 2; ++c) {
                        cin >> drop[i][k][l][c];
                    }
                }
            }
        }

        int ans = 0;
        vector<vector<vector<vector<char>>>>
                block(N, vector<vector<vector<char>>>(2, vector<vector<char>>(2, vector<char>(2, '.'))));


//        for (int dl = -1; dl <= 1; ++dl) {
//            for (int dc = -1; dc <= 1; ++dc) {
//
//            }
//        }
        for (int bit = 0; bit < (int) round(pow(3, 2 * N)); ++bit) {
//            vector<vector<vector<int>>> dlc(N, vector<vector<int>>(2, vector<int>(2, 0)));
//            vector<vector<int>> dl(N, vector<int>(2, 0));
//            vector<vector<int>> dc(N, vector<int>(2, 0));
            vector<int> dl(N);
            vector<int> dc(N);

            for (int i = 0; i < N; ++i) {
//                for (int l = 0; l < 2; ++l) {
////                    for (int c = 0; c < 2; ++c) {
////                        dlc[i][l][c] = getketa(bit, 4 * i + 2 * h + lc) - 1;
////                    }
//                    int keta = 4 * i + l;
//                    dl[i][l] = getketa(bit, keta);
//                }
//                for (int c = 0; c < 2; ++c) {
//                    int keta = 4 * i + c + 2;
//                    dc[i][c] = getketa(bit, keta);
//                }
                dl[i] = getketa(bit, 2 * i) - 1;
                dc[i] = getketa(bit, 2 * i + 1) - 1;
            }

            //ずらす
            if (dl[0] == 0 && dl[1] == 1 && dc[0] == 0 && dc[1] == 1) {
                int tapi = 79;
            }
            bool flag = true;
            block.assign(N, vector<vector<vector<char>>>(2, vector<vector<char>>(2, vector<char>(2, '.'))));

            for (int i = 0; i < N; ++i) {
                for (int h = 0; h < 2; ++h) {
                    for (int l = 0; l < 2; ++l) {
                        for (int c = 0; c < 2; ++c) {
                            int nl = l + dl[i];
                            int nc = c + dc[i];
                            if ((nl < 0 || nl >= 2) && drop[i][h][l][c] == '#') {
                                flag = false;
                                continue;
                            }
                            if ((nc < 0 || nc >= 2) && drop[i][h][l][c] == '#') {
                                flag = false;
                                continue;
                            }
                            if (drop[i][h][l][c] == '#')
                                block[i][h][nl][nc] = drop[i][h][l][c];
                        }
                    }
                }
            }


//            for (int i = 0; i < N; ++i) {
//                for (int j = 0; j < 2; ++j) {
//                    for (int h = 0; h < 2; ++h) {
//                        for (int w = 0; w < 2; ++w) {
//                            int pt = i * 8 + j * 4 + h * 2 + w;
//                            if (bit >> pt & 1) {
//                                block[i][j][h][w] = '#';
//                            } else {
//                                block[i][j][h][w] = '.';
//                            }
//                        }
//                    }
//                }
//            }

//            bool check = true;
//            for (int i = 0; i < N; ++i) {
//                for (int j = 0; j < 2; ++j) {
//                    int cnt = 0;
//                    for (int h = 0; h < 2; ++h) {
//                        for (int w = 0; w < 2; ++w) {
//                            if (block[i][j][h][w] == '#') cnt++;
//                        }
//                    }
//                    if (drop[i][j] != cnt) check = false;
//                }
//            }


            if (flag) {
                int tmp = run(block);
                chmax(ans, tmp);
            }
        }

        cout << ans << endl;
        return true;

    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    while (Solve().solve());

    return 0;
}

