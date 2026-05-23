#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;

    while(n!=0){
        vector<int> sub(n,0);
        for(int j = 0;j<m;j++){
            for(int i = 0;i<n;i++){
                int a;
                cin >> a;
                sub.at(i) += a;
            }
        }

        sort(sub.begin(),sub.end());

        cout << sub.at(n-1) << endl;

        cin >> n >> m;
    }
    
}
