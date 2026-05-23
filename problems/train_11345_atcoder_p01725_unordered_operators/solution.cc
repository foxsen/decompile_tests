#include <bits/stdc++.h>

using namespace std;

namespace {

    typedef long long Long;

    template<class T> ostream& operator<<(ostream& os, const vector<T>& vs) {
        if (vs.empty()) return os << "[]";
        os << "[" << vs[0];
        for (int i = 1; i < vs.size(); i++) os << "," << vs[i];
        return os << "]";
    }

    string s;
    void input() {
        cin >> s;
    }

    vector<string> ops; /* levelと演算子の対応. levelが大きいほど優先度が高い. */
    Long number(const string& s, int& index) {
        Long r = 0;
        while (index < s.size() && isdigit(s[index])) {
            r = r * 10 + (s[index] - '0');
            index++;
        }
        return r;
    }

    bool check(char op, int level) {
        // opが当該levelの演算子かどうかを返す
        for (int i = 0; i < ops[level].size(); i++) {
            if (op == ops[level][i]) return true;
        }
        return false;
    }

    Long calc(char op, Long a, Long b) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        assert(0);
    }

    Long parse(const string& s, int& index, int level) {
        if (level == 3) {
            if (s[index] == '(') {
                index++;
                Long r = parse(s, index, 0);
                assert(s[index] == ')');
                index++;
                return r;
            }
            return number(s, index);
        }
        Long r = parse(s, index, level + 1);
        while (index < s.size() && check(s[index], level)) {
            char op = s[index];
            index++;
            Long a = parse(s, index, level + 1);
            r = calc(op, r, a);
        }
        return r;
    }

    const Long INF = LLONG_MIN;

    void solve() {
        // 各演算子のlevelに対して全探索.
        string t = "+-*";
        sort(t.begin(), t.end());
        Long ans = -INF;
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                for (int c = 0; c < 3; c++) {
                    for (int i = 0; i < 4; i++) {
                        ops.clear(); ops.resize(3);
                        ops[a].push_back(t[0]);
                        ops[b].push_back(t[1]);
                        ops[c].push_back(t[2]);
                        int index = 0;
                        ans = max(ans, parse(s, index, 0));
                    }
                }
            }
        }
        cout << ans << endl;
    }
}

int main() {
    input(); solve();
    return 0;
}