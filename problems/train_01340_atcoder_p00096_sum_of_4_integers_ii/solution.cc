#include<iostream>
using namespace std;

int main(){

	int n;

	long long int tbl[5][4001] = { 0 };
	//0  <= a <= 1000
	tbl[0][0] = 1;

	for (int i = 1; i < 5; i++){
		for (int j = 0; j < 4001; j++){
			for (int k = 0 ; k < 1001; k++){
				if (j - k < 0) break;
				tbl[i][j] += tbl[i - 1][j-k];
			}
		}
	}

	while (cin >> n){
		cout << tbl[4][n] << endl;
	}

	return 0;
}