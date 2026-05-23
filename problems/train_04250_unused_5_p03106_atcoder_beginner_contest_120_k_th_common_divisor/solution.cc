#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int d=0;
	for(int i=a;i>=1;i--){
		if(a%i==0&&b%i==0){
			c--;
			if(c==0){
				cout<<i<<endl;
				return 0;
			}
		}
	}
}
