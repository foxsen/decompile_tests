#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
	std::ios_base::sync_with_stdio();

	string inp;
	int As,Bs;

	while(1){
		cin>>inp;
		if(inp=="0") break;
		As=0,Bs=0;
		for(int i=1;i<inp.length();i++){
			if(inp[i]=='A') As++;
			else Bs++;
		}
		if(max(As,Bs)==As) As++;
		else Bs++;
		cout<<As<<" "<<Bs<<endl;
	}

	return 0;
}