#include<cmath>
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main() {int n;cin>>n;vector<char> v(n);int t;cin>>t; 
vector<int> g(n);long long s=0;
for(int i=0;i<n;i++) {cin>>v[i];  s+=v[i]-96;g[i]=s;}
while(t--){
         int a,b;cin>>a>>b;
         if(a==1) cout<<g[b-1]<<" \n";
    else  cout<<g[b-1]-g[a-2]<<"\n";
         }
    return 0;
}