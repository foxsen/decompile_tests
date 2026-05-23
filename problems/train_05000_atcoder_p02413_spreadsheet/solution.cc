/*
 * itikara.cpp
 *
 *  Created on: 2018/05/30
 *      Author: J01003
 */
#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int k,b,n,c,r;
	cin>>r>>c;
int hyou[116][116];
for(k=1;k<=r;k++){
for(b=1;b<=c;b++){
		cin>>n;
		hyou[k][b] += n;
		hyou[r+1][b]+= n;
		hyou[k][c+1]+= n;
		hyou[r+1][c+1]+= n;
}}
for(k=1;k<=r+1;k++){
for(b=1;b<=c+1;b++){
	cout<<hyou[k][b];
	if(b>c){
		break;
	}
	cout<<" ";
}
cout<<endl;
}
	return 0;
}

