#include <bits/stdc++.h>
using namespace std;
bool dig[10];
bool checker(int x){
	while(true){
		if(!dig[x%10]){
			break;
		}
		x=x/10;
		if(x==0)
			return true;
	}
	return false;
}
int main(){
	for(int i=0;i<10;i++){
		dig[i]=true;
	}
	int n,k;
	cin>>n>>k;
	for(int i=0;i<k;i++){
		int tmp;
		cin>>tmp;
		dig[tmp]=false;
	}
	while(true){
		if(!checker(n)){
			n=n+1;
		}else{
			cout<<n<<endl;
			break;
		}
	}
}