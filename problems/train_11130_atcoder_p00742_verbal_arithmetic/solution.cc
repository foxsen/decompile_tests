#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define N 15

int imax, jmax, solution, digit[256], low[256];
char word[N][16];
bool ok[10];

void found(void){
	for(int i=0; i<imax; i++){
		if(strlen(word[i])>1&&digit[word[i][strlen(word[i])-1]]==0)return;
	}
	++solution;
}

void solve(int sum){
	static int i=0, j=0, carry;
	int c, d;

	c = word[i][j];
	if(i < imax-1) {
		i++;
		if((d = digit[c]) < 0) {
			for(d = low[c]; d <= 9; d++)
				if(ok[d]) {
					digit[c] = d;  ok[d] = false;
					solve(sum + d);  ok[d] = true;
				}
			digit[c] = -1;
		} else solve(sum + d);
		i--;
	} else {
		j++;  i=0;  d = sum % 10;  carry = sum / 10;
		if(digit[c] == d) {
			if(j <= jmax) solve(carry);
			else if(carry == 0) found();
		} else if(digit[c] < 0 && ok[d] && d >= low[c]) {
			digit[c] = d;  ok[d] = false;
			if(j <= jmax) solve(carry);
			else if(carry == 0) found();
			digit[c] = -1;  ok[d] = true;
		}
		j--;  i = imax-1;
	}
}

int main(){
	int k, c;
	char buffer[128];

	jmax = 0;
	while(1){
		cin >> imax;
		if(!imax) break;
		fill(word[0], word[16], 0);
		fill(digit, digit+256, 0);
		fill(ok, ok+10, false);
		for(int i=0; i<imax; i++) {
			cin >> buffer;
			k = strlen((char*)buffer) - 1;
			if(k > jmax) jmax = k;
			for(int j=0; j<=k; j++) {
				c = word[i][j] = buffer[k - j];
				if(isalpha(c)) digit[c] = -1;
				else if(isdigit(c)) digit[c] = c - '0';
			}
		}
		for(int i=0; i<=9; i++) ok[i] = true;
		solution = 0;
		solve(0);
		cout << solution << endl;
	}
	return 0;
}
