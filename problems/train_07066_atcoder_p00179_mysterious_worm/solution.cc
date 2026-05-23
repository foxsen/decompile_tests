#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(){
	
	while(true){
		string str;
		cin >> str;
		if(str[0] == '0'){
			break;
		}
		map<string, int> m;
		
		queue<string> que;
		que.push(str);
		
		for(int loop = 0; loop < 10000000; loop++){
			int N = que.size();
			if(N == 0){
				break;
			}
			for(int poyo = 0; poyo < N; poyo++){
				string s = que.front();
				//cout << s << endl;
				que.pop();
				if(m.find(s) != m.end()){
					continue;
				}
				m[s] = loop;
				for(int i = 0; i < s.size() - 1; i++){
					string ss = s;
					if(s[i] != s[i + 1]){
						if(s[i] != 'r' && s[i + 1] != 'r'){
							ss[i] = 'r';
							ss[i + 1] = 'r';
						}else if(s[i] != 'b' && s[i + 1] != 'b'){
							ss[i] = 'b';
							ss[i + 1] = 'b';
						}else{
							ss[i] = 'g';
							ss[i + 1] = 'g';
						}
					}
					que.push(ss);
				}
			}
		}
		int ans = 10000000;
		for(int i = 0; i < str.size(); i++){
			str[i] = 'r';
		}
		if(m.find(str) != m.end()){
			ans = min(ans, m[str]);
		}
		for(int i = 0; i < str.size(); i++){
			str[i] = 'b';
		}
		if(m.find(str) != m.end()){
			ans = min(ans, m[str]);
		}
		for(int i = 0; i < str.size(); i++){
			str[i] = 'g';
		}
		if(m.find(str) != m.end()){
			ans = min(ans, m[str]);
		}
		if(ans == 10000000){
			cout << "NA" << endl;
		}else{
			cout << ans << endl;
		}
	}
	
	return 0;
}