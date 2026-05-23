/* 
 * File:   main.cpp
 * Author: Prowindy
 *
 * Created on 2011å¹´8æ24æ¥, ä¸å2:27
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <queue>
using namespace std;
int dp[16][16][8][8][8];

int main() {
    for (int h, w; scanf("%d%d", &h, &w) && h;) {
        int table[16][16];
        int x, y;
         for (y = 0; y < h; y++)
        for (x = 0; x < w; x++)
                scanf("%d", &table[x][y]);

        int startX, startY, goalX, goalY;
        cin >> startY >> startX >> goalY >> goalX;
        vector<int> node;
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > q;
        {

            node.push_back(0);
            node.push_back(startX);
            node.push_back(startY);
            node.push_back(1);
            node.push_back(2);
            node.push_back(3);
            q.push(node);
        }

        memset(dp, 100, sizeof (dp));

        int oo = dp[0][0][0][0][0];
        dp[startX][startY][1][2][3] = 0;

        while (!q.empty()) {
            const vector<int> node = q.top();
            q.pop();
            const int cost = node[0];
            const int x = node[1];
            const int y = node[2];
            const int up = node[3];
            const int south = node[4];
            const int east = node[5];

            if (dp[x][y][up][south][east] != cost) {
                continue;
            }

            // æ±è¥¿åå
            for (int dir = 0; dir < 4; ++dir) {
                int nx, ny, nup, nsouth, neast, ncost;

                switch (dir) {
                    case 0:
                        //æ±
                        if (x + 1 == w) {
                            continue;
                        }
                        nx = x + 1;
                        ny = y;
                        nup = 7 - east;
                        nsouth = south;
                        neast = up;
                        break;
                    case 1:
                        //è¥¿
                        if (x == 0) {
                            continue;
                        }
                        nx = x - 1;
                        ny = y;
                        nup = east;
                        nsouth = south;
                        neast = 7 - up;
                        break;
                    case 2:
                        //å
                        if (y + 1 == h) {
                            continue;
                        }
                        nx = x;
                        ny = y + 1;
                        nup = 7 - south;
                        nsouth = up;
                        neast = east;
                        break;
                    case 3:
                        //å
                        if (y == 0) {
                            continue;
                        }
                        nx = x;
                        ny = y - 1;
                        nup = south;
                        nsouth = 7 - up;
                        neast = east;
                        break;
                }

                ncost = cost + table[nx][ny] * (7 - nup);

                if (dp[nx][ny][nup][nsouth][neast] <= ncost) {
                    continue;
                }
                dp[nx][ny][nup][nsouth][neast] = ncost;

                vector<int> next;
                next.push_back(ncost);
                next.push_back(nx);
                next.push_back(ny);
                next.push_back(nup);
                next.push_back(nsouth);
                next.push_back(neast);

                q.push(next);
            }
        }

        int best = oo;
        for (int i = 1; i <= 6; ++i) {
            for (int j = 1; j <= 6; ++j) {
                for (int k = 1; k <= 6; ++k) {
                    best = min(best, dp[goalX][goalY][i][j][k]);
                }
            }
        }
        cout << best << endl;
    }
}