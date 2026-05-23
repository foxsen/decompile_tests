#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,m,r,g,b,i,j,k,cur,ans=0,res,zero=0;

	cin >> n;
	vector<string> s(n);
	for(i=0; i<n; i++){
		cin >> s[i];
	}
	
	long long cura=0,curb=0,flag=0;
	for(i=0; i<n; i++){
		if(s[i][0]=='B'){
			curb++;
		}
		if(s[i][s[i].size()-1]=='A'){
			cura++;
			if(s[i][0]!='B'){
				flag++;
			}
		}
		for(j=1; j<s[i].size(); j++){
			if(s[i][j-1]=='A' && s[i][j]=='B'){
				ans++;
			}
		}
	}
	if(flag==0){
		curb=max(curb-1,zero);
	}
	cout << ans+min(cura,curb);

	return 0;
}
