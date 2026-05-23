#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long LL;
inline int toint(char c){
    if(isdigit(c)) return c - '0';
    else if(isupper(c)) return c - 'A' + 10;
    else if(islower(c)) return c - 'a' + 36;
}

int main(){
    int n;
    while(cin >> n){
        LL sum = 0;
        for(int i = 0; i < n; i++){
            LL x = 0;
            int p;
            char m[100];
            scanf("%d %s", &p, m);
            for(int idx = 0; m[idx]; idx++){
                x = x * p + toint(m[idx]);
            }
            sum = sum ^ x;
        }
        if(sum == 0){
            cout << "lose" << endl;
        }else{
            cout << "win" << endl;
        }
    }
    return 0;
}