#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define MAX_N 40
#define INF 1000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int p[4][4];
int pp[4][4];
int me;
bool y[4];
int po[4], gd[4], go[4];
string str;

int comp(int z){
    if(po[me] > po[z]) return 0;
    if(po[me] < po[z]) return 1;
    if(gd[me] > gd[z]) return 0;
    if(gd[me] < gd[z]) return 1;
    if(go[me] > go[z]) return 0;
    if(go[me] < go[z]) return 1;
    return 2;
}

double func(int st, int en){
    rep(i,4){
        if(y[i]) continue;
        po[i] = 0; gd[i] = 0; go[i] = 0;
    }
    rep(i,4){
        for(int j = i+1; j < 4; j++){
            if(y[i] == true || y[j] == true) continue;
            if(pp[i][j] > pp[j][i]){
                po[i] += 3;
            } else if(pp[i][j] < pp[j][i]){
                po[j] += 3;
            } else{
                po[i] += 1; po[j] += 1;
            }
            gd[i] += pp[i][j]-pp[j][i];
            gd[j] += pp[j][i]-pp[i][j];
            go[i] += pp[i][j];
            go[j] += pp[j][i];
        }
    }
    int sst = st, een = en;
    rep(i,4){
        if(y[i]) continue;
        if(i == me) continue;
        int co = comp(i);
        if(co == 0){
            een--;
            y[i] = true;
        } else if(co == 1){
            sst++;
            y[i] = true;
        }
    }
    if(een <= 2) return 1.0;
    if(sst >= 3) return 0.0;
    if(sst == st && een == en) return 1.0*(3-sst)/(een-sst+1);
    return func(sst,een);
}

double kaku(int x){
    double ret = 1.0;
    for(int i = 1; i <= 8; i++) ret *= i;
    for(int i = 1; i <= x; i++) ret /= i;
    for(int i = 1; i <= 8-x; i++) ret /= i;
    ret *= pow(0.25,x);
    ret *= pow(0.25*3,8-x);
    return ret;
}

void solve(){
    cin >> str;
    rep(i,4){
        cin >> str;
        if(str[0] == '*') me = i;
        if(i == 0){
            if(str[11] == '_'){
                p[0][1] = -1;
                p[1][0] = -1;
            } else{
                p[0][1] = str[11]-'0';
                p[1][0] = str[13]-'0';
            }
            if(str[16] == '_'){
                p[0][2] = -1;
                p[2][0] = -1;
            } else{
                p[0][2] = str[16]-'0';
                p[2][0] = str[18]-'0';
            }
            if(str[21] == '_'){
                p[0][3] = -1;
                p[3][0] = -1;
            } else{
                p[0][3] = str[21]-'0';
                p[3][0] = str[23]-'0';
            }
        } else if(i == 1){
            if(str[16] == '_'){
                p[1][2] = -1;
                p[2][1] = -1;
            } else{
                p[1][2] = str[16]-'0';
                p[2][1] = str[18]-'0';
            }
            if(str[21] == '_'){
                p[1][3] = -1;
                p[3][1] = -1;
            } else{
                p[1][3] = str[21]-'0';
                p[3][1] = str[23]-'0';
            }
        } else if(i == 2){
            if(str[21] == '_'){
                p[2][3] = -1;
                p[3][2] = -1;
            } else{
                p[2][3] = str[21]-'0';
                p[3][2] = str[23]-'0';
            }
        }
    }
    double ans = 0.0;
    rep(i,9) rep(j,9) rep(k,9) rep(l,9){
        rep(ii,4) rep(jj,4) pp[ii][jj] = p[ii][jj];
        int counter = 0;
        rep(ii,4) rep(jj,4){
            if(pp[ii][jj] == -1){
                if(counter == 0) pp[ii][jj] = i;
                if(counter == 1) pp[ii][jj] = j;
                if(counter == 2) pp[ii][jj] = k;
                if(counter == 3) pp[ii][jj] = l;
                counter++;
            }
        }
        double now = kaku(i)*kaku(j)*kaku(k)*kaku(l);
        memset(y,0,sizeof(y));
        ans += now*func(1,4);
    }
    printf("%.9f\n",ans);
}

int main(){
    int T;
    cin >> T;
    rep(i,T){
        solve();
    }
}