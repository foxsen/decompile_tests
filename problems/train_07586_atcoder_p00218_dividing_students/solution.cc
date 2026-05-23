#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n, pm, pe, pj, ave;
//	vector<int> ave;
	while(cin >> n, n){
		for(int i = 0; i < n; i++){
			cin >> pm >> pe >> pj;
			ave = (pm + pe + pj) / 3;
			if(pm == 100 || pe == 100 || pj == 100) cout << "A" << endl;
			else if((pm + pe)/2 >= 90) cout << "A" << endl;
			else if(ave >= 80) cout << "A" << endl;
			else if(ave >= 70) cout << "B" << endl;
			else if(ave >= 50 && (pm >= 80 || pe >= 80)) cout << "B" << endl;
			else cout << "C" << endl;
		 }
	}
}