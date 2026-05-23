#include<iostream>
#include<cctype>
#include<string>
using namespace std;

int main(){
	int n,sum=0;
	string s;
	while(cin>>s){
		n=0;
		for(int i=0;i<s.size();i++){
			if(isdigit(s[i]))n = 10*n+s[i]-'0';
			else {
				sum += n;
				n=0;
			}
		}
		sum += n;
	}
	cout<<sum<<endl;
	return 0;
}