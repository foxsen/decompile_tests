#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,h;
    cin>>n>>h;
    int a[n],b[n];
    int normal=0;//通常攻撃の最大値
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        normal=max(normal,a[i]);
    }
    sort(b,b+n,greater<int>());
    int x=0;
    while(x<n && b[x]>normal && h>0){
        h-=b[x];
        x++;
    }
    if(h<=0)cout<<x<<endl;
    else cout<<x+(h-1)/normal+1<<endl;
    return 0;
}