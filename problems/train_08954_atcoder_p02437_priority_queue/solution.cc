#include "bits/stdc++.h"
#define rep(i,a,n) for(int i = a;i < n;i++)
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    
    vector<priority_queue<int> > vec(n);
    
    int a,b,c;
    
    rep(i,0,q){
        cin >> a;
        
        if(a == 0){
            cin >> b >> c;
            vec[b].push(c);
        }
        else if(a == 1){
            cin >> b;
            if(!vec[b].empty()) cout << vec[b].top() << endl;
        }
        else{
            cin >> b;
            if(!vec[b].empty()) vec[b].pop();
        }
        
    }
    
    return 0;
}
