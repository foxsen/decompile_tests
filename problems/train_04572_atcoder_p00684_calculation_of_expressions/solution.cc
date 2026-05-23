#include<string>
#include<complex>
#include<cstdlib>
#include<iostream>

#define	rep(i,n)	for(int i=0;i<n;i++)

using namespace std;

bool overflow;

void checkOverflow(const complex<int> z){
	if(abs(real(z))>10000 || abs(imag(z))>10000)	overflow=true;
}

complex<int> term(const string &s,int &idx);
complex<int> factor(const string &s,int &idx);
complex<int> complex1(const string &s,int &idx);
complex<int> complex2(const string &s,int &idx);
complex<int> number(const string &s,int &idx);

complex<int> expr(const string &s,int &idx){
	complex<int> a=term(s,idx);
	while(idx<s.length() && (s[idx]=='+' || s[idx]=='-')){
		char ope=s[idx++];
		complex<int> b=term(s,idx);
		if(ope=='+')	a+=b;
		else			a-=b;
		checkOverflow(a);
	}
	return a;
}

complex<int> term(const string &s,int &idx){
	complex<int> a=factor(s,idx);
	while(idx<s.length() && s[idx]=='*'){
		idx++;
		complex<int> b=factor(s,idx);
		a*=b;
		checkOverflow(a);
	}
	return a;
}

complex<int> factor(const string &s,int &idx){
	complex<int> a;
	if(s[idx]=='('){
		idx++;
		a=expr(s,idx);
		idx++;
	}
	else	a=complex1(s,idx);
	return a;
}

complex<int> complex1(const string &s,int &idx){
	complex<int> a;
	if(s[idx]=='+' || s[idx]=='-'){
		char ope=s[idx++];
		a=complex1(s,idx);
		if(ope=='-')	a*=-1;
	}
	else	a=complex2(s,idx);
	return a;
}

complex<int> complex2(const string &s,int &idx){
	if(s[idx]=='i'){
		idx++;
		return complex<int>(0,1);
	}
	else	return number(s,idx);
}

complex<int> number(const string &s,int &idx){
	int a=0;
	while(idx<s.length() && isdigit(s[idx])){
		a=10*a+(s[idx++]-'0');
		checkOverflow(a);
	}
	return a;
}

complex<int> parse(const string &s){
	int idx=0;
	return expr(s,idx);
}

int main(){
	for(string s;cin>>s;){
		overflow=false;
		complex<int> ans=parse(s);
		if(overflow)	puts("overflow");
		else{
			if(imag(ans)==0)		printf("%d\n",real(ans));
			else if(real(ans)==0)	printf("%di\n",imag(ans));
			else					printf("%d%+di\n",real(ans),imag(ans));
		}
	}

	return 0;
}