#include <iostream>
using namespace std;
int main(){
	int max=0;
	char lb='A';
	for(int i=0,s1,s2;i<5;++i){
		cin>>s1>>s2;
		if(s1==0&&s2==0) break;
		if(s1+s2>max){
			max=s1+s2;
			lb='A'+i;
		}
		if(i==4){
			cout<<lb<<" "<<max<<"\n";
			max=0;
			i=-1;
			lb='A';
		}
	}
	return 0;
}