#include<iostream>
using namespace std;
int main(){
	int x,k;
	cin>>k>>x;
	for(int i=(x-k+1);i<=(x+k-1);i++){
		cout<<i<<" ";
	}
	return 0;
}