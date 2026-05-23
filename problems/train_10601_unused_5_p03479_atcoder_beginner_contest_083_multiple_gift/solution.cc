#include<iostream>
using namespace std;;
int main(){
long long  x,y;
cin >> x>>y;
long long count=0;
while(x <=y){
count++;
x= x*2;
}
cout <<count;
return 0;
}