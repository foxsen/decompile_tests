#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
using P = pair<int, int>;
using PP = pair<P, int>;
int W, H;
int sy, sx, sd;
int gy, gx, gd;
bool field[16][64];
bool used[16][64][4][16][64][4];
bool used2[16][64][4];
constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {-1, 0, 1, 0};

void init()
{
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 64; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 16; l++) {
                    for (int m = 0; m < 64; m++) {
                        for (int n = 0; n < 4; n++) {
                            used[i][j][k][l][m][n] = false;
                        }
                    }
                }
            }
        }
    }
}

P front(const int y, const int x, const int d)
{
    if (d == 0) {
        int Y = y;
        for (; field[Y - 1][x]; Y--) {
        }
        return {Y, x};
    } else if (d == 1) {
        int X = x;
        for (; field[y][X + 1]; X++) {
        }
        return {y, X};
    } else if (d == 2) {
        int Y = y;
        for (; field[Y + 1][x]; Y++) {
        }
        return {Y, x};
    } else {
        int X = x;
        for (; field[y][X - 1]; X--) {
        }
        return {y, X};
    }
}

vector<PP> back(const int y, const int x, const int d)
{
    vector<PP> ans;
    constexpr int R = 1;
    constexpr int L = 3;
    if (d == 0) {
        int Y = y;
        for (; field[Y][x]; Y--) {
            if (not field[Y][x + 1]) {
                ans.push_back({{Y, x}, L});
            }
            if (not field[Y][x - 1]) {
                ans.push_back({{Y, x}, R});
            }
        }
    } else if (d == 1) {
        int X = x;
        for (; field[y][X]; X++) {
            if (not field[y + 1][X]) {
                ans.push_back({{y, X}, L});
            }
            if (not field[y - 1][X]) {
                ans.push_back({{y, X}, R});
            }
        }
    } else if (d == 2) {
        int Y = y;
        for (; field[Y][x]; Y++) {
            if (not field[Y][x + 1]) {
                ans.push_back({{Y, x}, R});
            }
            if (not field[Y][x - 1]) {
                ans.push_back({{Y, x}, L});
            }
        }
    } else {
        int X = x;
        for (; field[y][X]; X--) {
            if (not field[y + 1][X]) {
                ans.push_back({{y, X}, R});
            }
            if (not field[y - 1][X]) {
                ans.push_back({{y, X}, L});
            }
        }
    }
    return ans;
}

bool dfs(int fy, int fx, int fd, int by, int bx, int bd)
{
    tie(fy, fx) = front(fy, fx, fd);
    vector<PP> cand = back(by, bx, bd);
    for (const auto& next : cand) {
        const int div = next.second;
        by = next.first.first;
        bx = next.first.second;
        const int newfd = (fd + div) % 4;
        const int newbd = (bd + div) % 4;
        if (fy == gy and fx == gx and by == gy and bx == gx and bd == gd) {
            return true;
        }
        if (not used[fy][fx][newfd][by][bx][newbd]) {
            used[fy][fx][newfd][by][bx][newbd] = true;
            const bool sub = dfs(fy, fx, newfd, by, bx, newbd);
            if (sub) {
                return true;
            }
        }
    }
    return false;
}

bool dfs(int fy, int fx, int fd)
{
    if (fy == gy and fx == gx) {
        return true;
    }
    tie(fy, fx) = front(fy, fx, fd);
    for (int i = -1; i <= 1; i += 2) {
        const int nd = (fd + i + 4) % 4;
        if (not used2[fy][fx][nd]) {
            used2[fy][fx][nd] = true;
            if (dfs(fy, fx, nd)) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int cnt = 0;
    while (true) {
        cnt++;
        cin >> W >> H;
        if (W == 0 and H == 0) {
            break;
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                char c;
                cin >> c;
                field[i][j] = c != '#';
                if (c == 'K') {
                    sy = i;
                    sx = j;
                } else if (c == 'M') {
                    gy = i;
                    gx = j;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            if (field[sy + dy[i]][sx + dx[i]]) {
                sd = i;
                break;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (field[gy + dy[i]][gx + dx[i]]) {
                gd = i;
                break;
            }
        }
        gd = (gd + 2) % 4;
        bool ans = false;
        for (int d = 0; d < 4; d++) {
            if (d > 0) {
                init();
            }
            used[sy][sx][sd][sy][sx][d] = true;
            if (dfs(sy, sx, sd, sy, sx, d)) {
                ans = true;
                break;
            }
        }
        if (ans) {
            cout << "He can accomplish his mission." << endl;
        } else {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 64; j++) {
                    for (int k = 0; k < 4; k++) {
                        used2[i][j][k] = false;
                    }
                }
            }
            used2[sy][sx][sd] = true;
            if (dfs(sy, sx, sd)) {
                cout << "He cannot return to the kitchen." << endl;
            } else {
                cout << "He cannot bring tea to his master." << endl;
            }
        }
    }

    return 0;
}

