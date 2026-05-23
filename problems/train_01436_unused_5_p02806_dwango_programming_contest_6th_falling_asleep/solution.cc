#include <iostream>
#include<string>
using namespace std;
int main(void){
    int c,m[50];
    cin>>c; //曲数

	string n[50];

	for(int i=0;i<c;i++){
		cin>>n[i];
		cin>>m[i];
	}

	string fm;
	cin>>fm;
	int j,sum=0;

	for(j=0;j<c;j++){
		if(fm==n[j]){
			j++;
			break;
		}
	}

	for(j=j;j<c;j++){
		sum=sum + m[j];
	}

	cout << sum << endl;
		return 0;
    
}