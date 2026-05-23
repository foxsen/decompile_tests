#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <ctime>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <numeric>
#include <cassert>
using namespace std;


string s;
int dfs(char c,int p){
	if( p == s.size() ){
		return c == 'B';
	}
	if( c == 'A' ){
		if(s[p]=='0'){
			if( dfs('X',p+1) ) return 1;
		}else if( dfs('Y',p+1) ) return 1;
	}
	if( c == 'B' ){
		if(s[p]=='0'){ if( dfs('Y',p+1) ) return 1;}
		else if( dfs('X',p+1) ) return 1;
	}
	if( c == 'X' ){
		if(s[p]=='1'){ if( dfs('Z',p+1) ) return 1;}
	}
	if( c == 'Y' ){
		if(s[p]=='0'){ if( dfs('X',p+1) ) return 1;}
	}
	if( c == 'W' ){
		if(s[p]=='0'){ if( dfs('B',p+1) ) return 1;}
		else if( dfs('Y',p+1) ) return 1;
	}
	if( c == 'Z' ){
		if(s[p]=='0'){ if( dfs('W',p+1) ) return 1;}
		else if( dfs('B',p+1) ) return 1;
	}
	return 0;
}
int main(){
	while(cin >> s && s != "#" ){
		cout << (dfs('A',0)?"Yes":"No") << endl;
	}
}