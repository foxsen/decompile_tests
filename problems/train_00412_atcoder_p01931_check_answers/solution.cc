#include<iostream>
#include<string>
using namespace std;

int main(){
	int N,i=0;
	string s;
	cin>>N>>s;
	for(i=1;i<N;i++){
		if(s[i]=='x'&&s[i-1]=='x')	break;
	}
	cout << i << endl;
	return 0;
}