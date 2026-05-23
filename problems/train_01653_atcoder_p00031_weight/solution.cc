#include <iostream>
using namespace std;
 
int main(void){
    int n,ans;
    while(cin>>n){
        for(int i=0;i<10;i++){
            if(n&1){
                ans=1<<i;
                cout<<ans;
                if(n>>1)
                    cout<<' ';
            }
            n>>=1;
        }
        cout << endl;
    }
}