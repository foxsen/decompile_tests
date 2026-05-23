#include <bits/stdc++.h>
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;

using P = pair <int, int>;
void hoge(vector <vector <P>> & origin, vector <P> vp);

int main() {
    int n;
    while (cin >> n, n) {
        vector <vector <P>> origin;

        int m;
        cin >> m;
        vector <P> tmp;
        rep (i, m) {
            int x, y;
            cin >> x >> y;
            tmp.emplace_back(x, y);
        }
        hoge(origin, tmp);
        reverse(tmp.begin(), tmp.end());
        hoge(origin, tmp);

        rep (i, n) {
            cin >> m;
            int x0, y0;
            vector <P> comparison;
            rep (j, m) {
                int x, y;
                cin >> x >> y;
                if (j == 0) {
                    x0 = x, y0 = y;
                    x = y = 0;
                }
                else {
                    x -= x0, y -= y0;
                }
                comparison.emplace_back(x, y);
            }

            if (comparison.size() != origin[0].size()) continue;
            rep (j, origin.size()) {
                bool flag = true;
                rep (k, origin[j].size()) flag &= (origin[j][k] == comparison[k]);
                if (flag) {
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
        cout << "+++++" << endl;
    }
    return 0;
}

void hoge(vector <vector <P>> & origin, vector <P> vp) {
    int x0 = vp.front().first, y0 = vp.front().second;
    vector <P> tmp = vp;
    vector <P> va = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    rep (i, 4) {
        vp = tmp;
        rep (j, vp.size()) {
            vp[j].first  -= x0;
            vp[j].second -= y0;

            vp[j].first  *= va[i].first;
            vp[j].second *= va[i].second;
            if (i > 1) swap(vp[j].first, vp[j].second);
        }
        origin.push_back(vp);
    }
}
