#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,k,t;
	bool f=true;
	vector<int> s;
	
	while(1){
		cin >> n >> k;
		if(n==0&&k==0) break;
		for(int i=0;i<k;i++){
			cin >> t;
			s.push_back(t);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++){
				cin >> t;
				s[j]-=t;
			}
		}
		
		for(int i=0;i<k;i++){
			if(s[i]<0){ f=false; }
		}
		if(f){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
		
		s.erase(s.begin(),s.end());
		f=true;
	}
	
	
}