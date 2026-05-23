#include <bits/stdc++.h>
#define inf 1000000000
using namespace std;

int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            int a[n];
            double temp;
            double x;
            bool found = 0;
            for(int i = 0 ; i < n ; i++) {
                cin>>a[i];
                temp = sqrt(a[i]);
                x = floor(temp);
                if ( temp != x ) found = 1;
            }
        if(found) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        }
        }
