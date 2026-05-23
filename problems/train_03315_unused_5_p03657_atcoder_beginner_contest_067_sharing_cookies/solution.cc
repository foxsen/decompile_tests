#include<iostream>
using namespace std;
int a,b;
int main(){
cin>>a>>b;
if((!((a+b)%3))||(!(b%3))||(!(a%3))) cout<<"Possible"<<endl;
else cout<<"Impossible"<<endl;}