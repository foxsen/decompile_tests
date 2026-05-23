#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
#include <queue>
#include <string.h>

#define MAX_N 1000

using namespace std;

int N;
char form[MAX_N+1][10000];
char res[MAX_N+1][10000];

int dfs(int level, int pnum){
	int prenum = pnum;
	if(level > 0){
		res[prenum][level-1] = '+';
		//res[pnum][level+1] = '\0';
	}
	strcpy(&res[prenum][level], &form[prenum][level]);
	
	int i, nexti;
	for (i = prenum+1; i < N; )
	{
		if(level < strlen(form[i]) && form[i][level] == '.' && form[i][level+1] != '.'){
			nexti = dfs(level+1, i);
			//cout << nexti << endl;
			for (int j = prenum+1; j < i; j++)
			{
				res[j][level] = '|';
			}
			prenum = i;
			i = nexti;
		}else{
			break;
		}
	}
	return i;
}

int main(){
	while(1){
		cin >> N;
		if(N == 0) break;
		for (int i = 0; i < N; i++)
		{
			cin >> form[i];
			for (int j = 0; j < strlen(form[i]); j++)
			{
				res[i][j] = ' ';
			}
			//res[i][strlen(form[i])] = '\0';
			//res[i][strlen(form[i])+1] = '\0';
		}
		dfs(0,0);
		for (int i = 0; i < N; i++)
		{
			cout << res[i] << endl;
		}
	}
	return 0;
}