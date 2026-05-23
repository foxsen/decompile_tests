#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

// s の方が大きいときに true
string max_s(const string &s, const string &t) {
    if(s.length() != t.length()) return (s.length() > t.length() ? s : t);
    else return (s > t ? s : t);
}

string min_s(const string &s, const string &t) {
    if(s.length() != t.length()) return (s.length() < t.length() ? s : t);
    else return (s < t ? s : t);
}

string dp[60][60], pat = "LR";
int main() {
    string s; cin >> s;
    int N = (int)s.length();

    for(int len=1; len<=N; len++) {
        for(int l=0; l<N-len+1; l++) {
            int r = l + len;
            // ただの数字
            bool can_num = true;
            string nxt = "";
            for(int i=l; i<r; i++) {
                if(r-l > 1 && i == l && s[i] == '0') can_num = false;
                else if(s[i] != '?' && !isdigit(s[i])) can_num = false;
                else if(s[i] == '?') nxt += '9';
                else nxt += s[i];
            }
            if(can_num) {
                dp[l][r] = max_s(dp[l][r], nxt);
            }

            // 左端を L or R にして括弧
            // カンマの位置を全部ためそう
            for(int t=0; t<2; t++) {
                if(s[l] == pat[t] || s[l] == '?') {
                    if(r-l < 6) continue;
                    if(s[l+1] != '?' && s[l+1] != '(') continue;
                    if(s[r-1] != '?' && s[r-1] != ')') continue;
                    for(int k=l+2; k<r-1; k++) {
                        if(s[k] != ',' && s[k] != '?') continue;
                        string v1 = dp[l+2][k];
                        string v2 = dp[k+1][r-1];
                        if(v1 == "" || v2 == "") continue;
                        string tmp = (pat[t] == 'L' ? v1 : v2);
                        dp[l][r] = max_s(dp[l][r], tmp);
                    }
                }
            }

            /*
            if(dp[l][r] != "") {
                cout << s << endl;
                for(int i=0; i<N; i++) {
                    if(l <= i && i < r) printf("=");
                    else printf(" ");
                }
                printf(" -> %s\n\n", dp[l][r].c_str());
            }
            */
        }
    }

    if(dp[0][N] == "") cout << "invalid" << endl;
    else cout << dp[0][N] << endl;
    return 0;
}
