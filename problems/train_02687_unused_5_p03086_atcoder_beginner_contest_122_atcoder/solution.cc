#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	int i,p=0,m=0;
	for(i=0;i<s.size();i++){
		if(s[i] =='A' || s[i] =='T' || s[i] == 'C' || s[i] == 'G'){
			p++;
			if(m<p) m = p;
		}else{
			p = 0;
		}
	}

	cout << m << endl;
				
	return 0;
}