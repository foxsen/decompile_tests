#include<bits/stdc++.h>
using namespace std;

int n;
char s[15];

void dfs(int dep,int mx){
    if(dep==n){
        puts(s);
        return;
    }
    for(int i=0;i<mx;i++){
        s[dep]=i+'a';
        dfs(dep+1,mx);
    }
    s[dep]=mx+'a';
    dfs(dep+1,mx+1);
}

int main(){

    scanf("%d",&n);
    dfs(0,0);

    return 0;
}