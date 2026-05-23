#include <iostream>
#include <string>

using namespace std;

int n;
string s[100005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j+2 < s[i].size(); j++){
			if(s[i].substr(j, 3) == "AOR") ans++;
		}
	}
	
	int Ocnt = 0, _A = 0, _AO = 0, R_ = 0, OR_ = 0, R_A = 0, OR_A = 0, R_AO = 0, OR_AO = 0;
	for(int i = 1; i <= n; i++){
		int l = s[i].size();
		if(s[i] == "O") Ocnt++;
		if(s[i].substr(l-1, 1) == "A")_A++;
		if(l >= 2 && s[i].substr(l-2, 2) == "AO") _AO++;
		if(s[i].substr(0, 1) == "R") R_++;
		if(l >= 2 && s[i].substr(0, 2) == "OR") OR_++;
		if(l >= 2 && s[i].substr(0, 1) == "R" && s[i].substr(l-1, 1) == "A") R_A++;
		if(l >= 3 && s[i].substr(0, 2) == "OR" && s[i].substr(l-1, 1) == "A") OR_A++;
		if(l >= 3 && s[i].substr(0, 1) == "R" && s[i].substr(l-2, 2) == "AO") R_AO++;
		if(l >= 4 && s[i].substr(0, 2) == "OR" && s[i].substr(l-2, 2) == "AO") OR_AO++;
	}
	int gomi = _A+_AO+R_+OR_ - (R_A+OR_A+R_AO+OR_AO) + Ocnt;
	gomi = n - gomi;
	
	int mx = 0;
	for(int i = 0; i <= min(Ocnt, _A); i++){
		int tmp1 = min(_A-i, OR_);
		if(tmp1 && OR_A == _A && OR_A == OR_ && i == 0) tmp1--;
		
		int tmp2 = min(_AO+i, R_);
		if(tmp2 && R_AO == _AO && R_AO == R_ && i == 0) tmp2--;
		
		mx = max(mx, tmp1+tmp2);
		//cout << tmp1 << " " << tmp2 << endl;
	}
	if(mx && mx == n-(Ocnt+gomi)) mx--;
	ans += mx;
	
	cout << ans << endl;
	
	return 0;
}
