#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

using vi = vector<int>;
using pii = pair<int, int>;

using state = tuple<vi, int, int>;
using result = array<int, 3>;

map<state, result> memo;
map<state, result> memo2;
map<state, state> next_st;
map<state, int> get_score;
int card[3][2];

array<int, 3> make_array(int a, int b, int c) {
    return {{a, b, c}};
}

enum {
    frog,  // maximize self score
    kappa, // minimize frog score
    weasel // maximize self score
};

result rec(vi fld, int action, int turn, bool k) {
    if(fld.size() == 0) {
        return make_array(0, 0, 0);
    }
    auto now = make_tuple(fld, action, turn);
    if((k ? memo2 : memo).count(now) == 1) {
        return (k ? memo2 : memo)[now];
    }
    auto& res = (k ? memo2 : memo)[now];
    res = make_array(0, 0, -INF);

    int sum = 0;
    for(int i = 0; i < 2; ++i) {
        if(action & (1 << (2 * turn + i))) {
            sum += card[turn][i];
        }
    }
    if(!k || turn == kappa) {
        vector<result> cand;
        vector<pii> comp;
        vector<vi> next_fld;
        vector<int> next_action;
        vector<int> add_score;
        { // pass
            auto f = fld;
            int score = *f.begin();
            f.erase(f.begin());
            auto t = rec(f, action, (turn + 1) % 3, k);
            t[turn] += score;
            cand.push_back(move(t));
            next_fld.push_back(f);
            next_action.push_back(action);
            add_score.push_back(score);
            if(turn == kappa && k) {
                comp.emplace_back(-cand.back()[frog], sum);
            } else {
                comp.emplace_back(cand.back()[turn], sum);
            }
        }
        for(int i = 0; i < 2; ++i) {
            if(action & (1 << (2 * turn + i)) && card[turn][i] <= fld.size()) {
                int nxt_act = action & ~(1 << (2 * turn + i));
                auto f = fld;
                int score = *(f.begin() + card[turn][i] - 1);
                f.erase(f.begin() + card[turn][i] - 1);
                auto t = rec(f, nxt_act, (turn + 1) % 3, k);
                t[turn] += score;
                cand.push_back(move(t));
                next_fld.push_back(f);
                next_action.push_back(nxt_act);
                add_score.push_back(score);
                if(turn == kappa && k) {
                    comp.emplace_back(-cand.back()[frog], sum - card[turn][i]);
                } else {
                    comp.emplace_back(cand.back()[turn], sum - card[turn][i]);
                }
            }
        }
        int idx = max_element(comp.begin(), comp.end()) - comp.begin();
        if(!k) {
            next_st[now] = make_tuple(next_fld[idx], next_action[idx], (turn + 1) % 3);
            get_score[now] = add_score[idx];
        }
        return res = cand[idx];
    } else {
        vi f;
        int a, t;
        tie(f, a, t) = next_st[now];
        auto tmp = rec(f, a, t, true);
        tmp[turn] += get_score[now];
        return res = tmp;
    }
}

int main() {
    vi fld(12);
    for(int i = 11; i >= 0; --i) {
        cin >> fld[i];
    }
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 2; ++j) {
            cin >> card[i][j];
        }
    }
    rec(fld, 0b111111, 0, false);
    auto res = rec(fld, 0b111111, 0, true);
    cout << res[0] << ' ' << res[1] << ' ' << res[2] << endl;
}
