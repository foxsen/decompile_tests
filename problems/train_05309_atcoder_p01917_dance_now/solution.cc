#include <bits/stdc++.h> 
#define rep(i, a, n) for(int i = a; i < n; i++)
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;

int d[3][210];
int r[110], n;


bool f(int c){
    vector<P> sc(n);
    int score[3][210] = {};
    rep(i, 0, 3){
        vector<int> tmp(n);
        rep(j, 0, n){
            tmp[j] = d[i][j];
        }
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        int now = -1;
        int rank = -1;
        rep(j, 0, n){
            if(tmp[j] != now){
                now = tmp[j];
                rank = j;
            }
            score[i][tmp[j]] = r[rank];
        }
        // rep(j, 0, 100){
        //     cout << score[i][j] << " ";
        // }
        // cout << endl;
    }
    vector<P> sum(n);
    rep(i, 0, n){
        sum[i].se = i;
        rep(j, 0, 3){
            sum[i].fi -= score[j][d[j][i]];
        }
    }
    sort(sum.begin(), sum.end());
    // rep(i, 0, n){
    //     cout << sum[i].se << " " << sum[i].fi << " " << endl;
    // }
    // cout << endl;
    rep(i, 0, 8){
        if(sum[i].se == 0) return true;
    }
    return false;
}


int main(){
    cin >> n;
    rep(i, 0, n) cin >> r[i];
    rep(i, 0, n){
        rep(j, 0, 3){
            cin >> d[j][i];
        }
    }

    rep(i, 0, 100){
        rep(j, 0, 3){
            d[j][0] += i;
            if(d[j][0] >  201) continue;
            if(f(j)){
                cout << i << endl;
                return 0;
            }
            d[j][0] -= i;
            // if(i == 3) return 0;
            // cout << endl;
        }
    }
    cout << "Saiko" << endl;
}