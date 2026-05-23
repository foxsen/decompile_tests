#include<iostream>
using namespace std;
int main(){
	const int MAX=46;
	long long f[MAX]={1,1};
	for(int i=2;i<MAX;i++)f[i]=f[i-1]+f[i-2];
	int n;
	cin>>n;
	cout<<f[n]<<endl;
	return 0;
}
