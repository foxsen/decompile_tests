#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int h,m;
		char _;
		cin>>h>>_>>m;
		int d=min(abs(h*60+m-12*m) , 720-max(h*60+m,12*m)+min(h*60+m,12*m));
		if(d<30*2){
			cout<<"alert\n";
		}else if(d<90*2){
			cout<<"warning\n";
		}else{
			cout<<"safe\n";
		}
	}
	return 0;
}