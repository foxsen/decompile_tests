#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	char WX[7][6],WY[6][7];
	for(int i=0;i<7;i++){
		for(int j=0;j<6;j++){
			WX[i][j] = 0;
			WY[j][i] = 0;
		}
	}
	for(int i=1;i<5;i++) cin >> WX[i][1];
	for(int i=1;i<6;i++) cin >> WY[1][i];
	for(int i=1;i<5;i++) cin >> WX[i][2];
	for(int i=1;i<6;i++) cin >> WY[2][i];
	for(int i=1;i<5;i++) cin >> WX[i][3];
	for(int i=1;i<6;i++) cin >> WY[3][i];
	for(int i=1;i<5;i++) cin >> WX[i][4];
	for(int i=1;i<6;i++) cin >> WY[4][i];
	for(int i=1;i<5;i++) cin >> WX[i][5];

	int NX = 1;
	int NY = 1;
	char s = 'R';
	while(1){
		if(s=='R'){
			if(WY[NY-1][NX]=='1'){ s = 'U'; NY--; cout << s;}
			else if(WX[NX][NY]=='1'){ NX++; cout << s;}
			else if(WY[NY][NX]=='1'){ s = 'D'; NY++; cout << s;}
			else s = 'L';
		}
		else if(s=='L'){
			if(WY[NY][NX]=='1'){ s = 'D'; NY++; cout << s;}
			else if(WX[NX-1][NY]=='1'){ NX--; cout << s;}
			else if(WY[NY-1][NX]=='1'){ s = 'U'; NY--; cout << s;}
			else s = 'R';
		}
		else if(s=='U'){
			if(WX[NX-1][NY]=='1'){ s = 'L'; NX--; cout << s;}
			else if(WY[NY-1][NX]=='1'){ NY--; cout << s;}
			else if(WX[NX][NY]=='1'){ s = 'R'; NX++; cout << s;}
			else s = 'D';
		}
		else if(s=='D'){
			if(WX[NX][NY]=='1'){ s = 'R'; NX++; cout << s;}
			else if(WY[NY][NX]=='1'){ NY++; cout << s;}
			else if(WX[NX-1][NY]=='1'){ s = 'L'; NX--; cout << s;}
			else s = 'U';
		}
		if(NX*NY==1) break;
	}
cout << endl;
}