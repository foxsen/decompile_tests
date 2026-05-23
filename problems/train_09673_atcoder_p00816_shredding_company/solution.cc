#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define debug(x) cout << "debug " << x << endl;
const int INF = 100000000;
using namespace std;

string s, ans_str;
int n, ans_num;
bool f[8];
map<int, int> m;

typedef string::const_iterator State;
int number(State&);
int factor(State&);
int term(State&);
int expression(State&);

// ??°??????????????????????????????????????°????????????
int number(State &begin) {
    int ret = 0;

    while (isdigit(*begin)) {
        ret *= 10;
        ret += *begin - '0';
        begin++;
    }

    return ret;
}

// ??¬??§?????°???????????????????????????????????????????????????
int factor(State &begin) {
    if (*begin == '(') {
        begin++; // '('????£???°??????
        int ret = expression(begin);
        begin++; // ')'????£???°??????
    } else {
        return number(begin);
    }
    return INF;
}

// ?????????????????????????????????????????????????????????????????????
int term(State &begin) {
    int ret = factor(begin);

    for (;;) {
        if (*begin == '*') {
            begin++;
            ret *= factor(begin);
        } else if (*begin == '/') {
            begin++;
            ret /= factor(begin);
        } else {
            break;
        }
    }

    return ret;
}

// ?????????????????????????????????????????????????????????????????????
int expression(State &begin) {
    int ret = term(begin);

    for (;;) {
        if (*begin == '+') {
            begin++;
            ret += term(begin);
        } else if (*begin == '-') {
            begin++;
            ret -= term(begin);
        } else {
            break;
        }
    }

    return ret;
}

void solve(string p, int i){
    if(i == s.size()){
        State it = p.begin();
        int temp = expression(it);
        if(abs(n - ans_num) >= abs(n - temp) && n >= temp){
            ans_str = p;
            ans_num = temp;
            m[temp]++;
        }
        return;
    }

    p+=s[i];
    solve(p, i + 1);
    if(i + 1 != s.size() && f[i] == 0 && f[i + 1] == 0){
        p+='+';
        solve(p, i + 1);
    }
}

void check(){
    string temp;
    int m = static_cast<int>(log10(n));

    rep(i,s.size() - m){
        string temp = s.substr(i,m);
        State it = s.begin();
        if(number(it) == n){
            range(j,i,i + m){
                f[j] = 1;
            }
        }
    }
}


int main(){
    while(cin >> n >> s, n||s[0] != '0'){
        m.clear();
        ans_num = -1;
        rep(i,8) f[i] = 0;

        solve("", 0);

        State it = s.begin();
        if(ans_num == -1){
            cout << "error" << endl;
        }else if(m[ans_num] > 1){
            cout << "rejected" << endl;
        }else{
            cout << ans_num << ' ';
            rep(i,ans_str.size()){
                if(ans_str[i] == '+') cout << ' ';
                else cout << ans_str[i];
            }
            cout << endl;
        }
    }
}