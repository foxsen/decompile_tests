#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

bool check(char a, char b, char c){
	if(a == 's') return false;
	return (a == b && b == c);
}

int main(){
	string s;
	char winner;

	while(cin >> s){
		winner = 'd';
		for(int i = 0; i < 3; i++){
			if( check(s[i], s[i+3], s[i+6]) ){
				winner = s[i];
				break;
			}
		}
		for(int i = 0; i < 9; i+=3){
			if( check(s[i], s[i+1], s[i+2]) ){
				winner = s[i];
				break;
			}
		}
		if( check(s[2], s[4], s[6]) || check(s[0], s[4], s[8]) ){
			winner = s[4];
		}

		cout << winner << endl;
	}
	
    return 0;
}