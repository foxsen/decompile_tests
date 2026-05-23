#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n, n){
        int cnt = 0;
        bool ok = false;
        for(int i=0;i<n;i++){
            int k;
            cin >> k;
            if(k>0) cnt++;
            if(k>1) ok = true;
        }
        if(ok){
            cout << cnt+1 << endl;
        }
        else{
            cout << "NA" << endl;
        }
    }
    return 0;
}
