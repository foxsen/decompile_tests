#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n,a[100000];
	cin>>n;
	for (int i = 1; i <= n; i++){
		cin>>a[i];
	}
	int btn=1,count=0;
	while(1){
		if(btn==2){
			cout<<count<<endl;
			return 0;
		}
		btn=a[btn];
		count++;
		if(count>n+1){
			cout<<-1<<endl;
			return 0;
		}
	}

}

