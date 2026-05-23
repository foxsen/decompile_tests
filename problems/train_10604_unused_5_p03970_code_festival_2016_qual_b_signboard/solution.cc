#include<bits/stdc++.h>
using namespace std;
int main(){
	string a="CODEFESTIVAL2016",b;
	cin>>b;
	int jsq=0;
	for(int i=0;i<a.length();i++){
		if(a[i]!=b[i])
			jsq++;
	}
	cout<<jsq;
}