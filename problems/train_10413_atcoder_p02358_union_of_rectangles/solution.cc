#include <bits/stdc++.h>
#include <numeric>
#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())

#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false
#define LL long long
#define Dev 1000000007

// sort(a.begin(), a.end(), std::greater<int>());
using namespace std;

struct lect
{
    int xs, xe, ys, ye;
};

int main()
{
    int n;
    cin >> n;
    vector<lect> lects(n);
    rep(i, n)
    {
        cin >> lects[i].xs >> lects[i].ys >> lects[i].xe >> lects[i].ye;
    }
    vector<long long int> largeX;
    vector<long long int> largeY;
    rep(i, lects.size())
    {
        largeX.push_back(lects[i].xs);
        largeX.push_back(lects[i].xe);
        largeY.push_back(lects[i].ys);
        largeY.push_back(lects[i].ye);
    }
    SORT(largeX);
    SORT(largeY);
    largeX.erase(std::unique(largeX.begin(), largeX.end()), largeX.end());
    largeY.erase(std::unique(largeY.begin(), largeY.end()), largeY.end());
    map<long long int, long long int> compX;
    map<long long int, long long int> compY;
    map<long long int, long long int> invCompX;
    map<long long int, long long int> invCompY;
    rep(i, largeX.size())
    {
        compX[largeX[i]] = i;
        invCompX[i] = largeX[i];
    }
    rep(i, largeY.size())
    {
        compY[largeY[i]] = i;
        invCompY[i] = largeY[i];
    }
    int compArea[largeX.size() + 2][largeY.size() + 2];

    rep(x, largeX.size() + 2)
    {
        rep(y, largeY.size() + 2)
        {
            compArea[x][y] = 0;
        }
    }

    for (auto lec : lects)
    {
        compArea[compX[lec.xs] + 1][compY[lec.ys] + 1] += 1;
        compArea[compX[lec.xe] + 1][compY[lec.ys] + 1] -= 1;
        compArea[compX[lec.xs] + 1][compY[lec.ye] + 1] -= 1;
        compArea[compX[lec.xe] + 1][compY[lec.ye] + 1] += 1;
    }
    //make imos

    rep(x, largeX.size() + 2)
    {
        REP(y, 1, largeY.size() + 2)
        {
            compArea[x][y] += compArea[x][y - 1];
        }
    }
    REP(x, 1, largeX.size() + 2)
    {
        rep(y, largeY.size() + 2)
        {
            compArea[x][y] += compArea[x - 1][y];
        }
    }


    long long int ans = 0;
    REP(x, 1, largeX.size() + 1)
    {
        REP(y, 1, largeY.size() + 1)
        {
            if (compArea[x][y] == 0)
                continue;
            else
                ans += abs(invCompX[x] - invCompX[x - 1]) * abs(invCompY[y] - invCompY[y - 1]);
            if (compArea[x][y] > 1)
            {
                compArea[x][y] = 0;
            }
        }
    }


    cout << ans << endl;
    return 0;
}
