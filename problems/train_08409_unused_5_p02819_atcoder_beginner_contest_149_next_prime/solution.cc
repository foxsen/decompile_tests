#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool hoge(int a){
    for(ll i=2;i*i <= a;i++){
        if(a%i == 0)return false;
    }
    return true;
}
int main(){
    int x;
    cin >> x;
    while(!hoge(x)){x++;}
    cout << x << endl;
}