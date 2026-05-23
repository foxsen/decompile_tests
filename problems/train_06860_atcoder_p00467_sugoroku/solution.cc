#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	int N,M;
	while(1){
	int n[4000]={};
	int G=0;
	int H=0;
	cin>>N>>M;if(N==0&&M==0)break;
	for(int i=0;i<N;i++)
	{
		
		cin>>n[i];
		
	}
	bool f=false;
	for(int i=0;i<M;i++)
	{
		int x;cin>>x;
		G+=x;
		G+=n[G];
		if(G>=N-1&&f==false){f=true;H=i+1;}
		//cout<<"#"<<i<<G<<endl;
	}
	cout<<H<<endl;
}
	return 0;
}
			
	