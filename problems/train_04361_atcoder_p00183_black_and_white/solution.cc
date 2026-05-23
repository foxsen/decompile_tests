#include <iostream>
#include <string>
using namespace std;

int main(){
	char d[9];
	string m[8]={"012","345","678","036","147","258","048","246"};
	int f;
	while(cin>>d[0],d[0]!='0'){
		for(int i=1;i<=8;i++)cin>>d[i];
		f=1;
		for(int i=0;i<8;i++){
			if(d[m[i][0]-'0']==d[m[i][1]-'0']&&d[m[i][1]-'0']==d[m[i][2]-'0']&&f&&d[m[i][0]-'0']!='+'){
				f=0;
				cout<<d[m[i][0]-'0']<<endl;
			}
			
		}
		if(f)cout<<"NA"<<endl;
	}
	
	
}
