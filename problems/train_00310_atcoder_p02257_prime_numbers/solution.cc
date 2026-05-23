#include<iostream>
using namespace std;

bool prime(int p){
for(int i=2;i*i<=p;i++)
if(!(p%i))return false;
return true;
}

int main(){
int n,p,ans=0;
cin >> n;
for(int i=0;i<n;i++){
cin >> p;
if(prime(p))ans++;
}
cout << ans << endl;
}