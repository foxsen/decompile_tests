#include<bits/stdc++.h>
using namespace std;
int a[1005];
int c[1005];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n;i++){
        cin >> c[i];
    }
    int q;
    cin >> q;
    while(q--){
        int t,x,d;
        cin >> t >> x >> d;
        if(t == 1){
            a[x] += d;
            if(a[x] > c[x]){
                 cout << x << endl;
                 return 0;
            }
        }else{
            a[x] -= d;
            if(a[x] < 0){
                cout << x << endl;
                return 0;
            }
        }
    }
    cout << 0 <<endl;

    return 0;
}

