#include <bits/stdc++.h>
using namespace std;
int n,s[111],z=1000,a;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if((s[i]%10)!=0){
			if(z>s[i])z=s[i];
		}
		a+=s[i];
	}
	if((a%10)==0)a-=z;
	if(z==1000)a=0;
	cout<<a<<endl;
}

