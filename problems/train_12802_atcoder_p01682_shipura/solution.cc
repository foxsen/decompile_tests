#include <iostream>
#include <string>
#include <cctype>
using namespace std;
typedef string::const_iterator State;
typedef long long ll;
ll mod=1000000007;
string s;
ll expression(State &begin);			//term or expr >> term
ll term(State &begin);					//num or S<expr>
ll number(State &begin);				//
string as(State &begin){
	string hoge;
	for(State st=s.begin();st!=s.end();st++){
		if(st==begin) hoge=hoge+" "+(*st)+" "; 
		else hoge+=(*st);
	}
	return hoge;
}
ll expression(State &begin){
//	cout << "expr  " << as(begin) << endl;
	ll ret=term(begin);
	if(*begin == '>'){
		begin--;	//>
//		if(*begin!='>') cout << "> " << as(begin) << endl;
		begin--;
		if(ret>40) ret=0*expression(begin);
		else ret=expression(begin) >> ret;
	}
	return ret;
}
ll term(State &begin){
//	cout << "term  " << as(begin) << endl;
	if(*begin == '>'){
		begin--;
		ll ret=expression(begin);
		ret*=ret;
		ret%=mod;
//		if(*begin!='<') cout << "< " << as(begin) << endl;
		begin--;	//S
//		if(*begin!='S') cout << "S " << as(begin) << endl;
//		cout << "t erm " << as(begin) << endl;
		begin--;
		return ret;
	}else{
		return number(begin);
	}
}
ll number(State &begin){
//	cout << "num   " << as(begin) << endl;
	ll ret=0,dig=1;
	while(isdigit(*begin)){
		ret+=dig*(*begin-'0');
		begin--;
		dig*=10;
	}
//	cout << "n um  " << as(begin) << endl;
	return ret;
}
int main(){
	for(;;){
		getline(cin,s);
		if(s[0]=='#') break;
		s="?"+s;
		string::iterator it;
		for(it=s.begin();it!=s.end();it++){
			if((*it)==' '){
				s.erase(it);
				it--;
			}
		}
		State begin=s.end();
		begin--;
		ll ans=expression(begin);
		cout << ans << endl;
	}
	return 0;
}