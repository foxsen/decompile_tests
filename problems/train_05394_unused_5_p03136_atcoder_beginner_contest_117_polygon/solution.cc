#include<iostream>
using namespace std;
int m,s,l,i,a;
int main(){
	cin>>a;
	while(a--){
		cin>>l;
		if(m<l)m=l;
		s+=l;}
	puts(s>m*2?"Yes":"No");}
