#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, x, c=0, d;
  cin>>n>>d>>x;
  	while(n--){
    	int a;
      	cin>>a;
      	for(int i=1;i<=d;i+=a){
        	c++;
        }
    }
  	cout<<c+x;
}
