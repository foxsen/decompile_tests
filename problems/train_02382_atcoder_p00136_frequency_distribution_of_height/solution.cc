#include <iostream>
#include <vector>
using namespace std;

int main(){
    double t;
    int n,h;
    vector<int> f(6,0);
    cin>>n;
    for(;n--;){
        cin>>t;
        if(t<165.0) h = 0;
        else h = ((int)t-160)/5;
        if(h>5)h=5;
        f[h]++;
    }
    for(n=0;n<6;n++){
        cout<<n+1<<":";
        while(f[n]--) cout<<"*";
        cout<<endl;
    }
    return 0;
}