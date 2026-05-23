#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const int INF = 2000000000;
using namespace std;

string toStr(int n){
    string str;
    int len = static_cast<int>(log10(n));
    int K = 1;
    rep(i,len) K*=10;
    rep(i,len + 1){
        if(n / K == 0) str+= '0';
        else str+= ('0' + n / K);
        n%=K; K/=10;
    }
    return str;
}

int main(){
    int n;
    int ans[2];
    cin >> n;

    int cnt = 0;
    while(true){
        string s = toStr(n + cnt);
        string r = s;
        reverse(all(r));
        if(s == r){
            ans[0] = cnt;
            break;
        }
        cnt++;
    }

    cnt = 0;
    while(true){
        string s = toStr(n - cnt);
        string r = s;
        reverse(all(r));
        if(s == r){
            ans[1] = cnt;
            break;
        }else if(n - cnt < 0){
            ans[1] = INF;
            break;
        }
        cnt++;
    }

    if(ans[1] < ans[0]) cout << n - ans[1] << endl;
    else if(ans[1] > ans[0]) cout << n + ans[0] << endl;
    else cout << n - ans[1] << endl;

    return 0;
}