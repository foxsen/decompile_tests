#include <iostream>
#include <vector>
#include <string>

using namespace std;

int abs(int a){ return a > 0 ? a : -a; }
int gcd(int a, int b){ return a%b ? gcd(b, a%b) : b; }
int lcm(int a, int b){ return a/gcd(a,b)*b; }

vector<int> mul(vector<int> a, vector<int> b){
	vector<int> res(a.size()+b.size()-1, 0);
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++)
			res[i+j] += a[i]*b[j];
	return res;
}

vector<int> pow(vector<int> vi, int p){
	vector<int> res(1,1);
	for(int i=0;i<p;i++)
		res = mul(res, vi);
	return res;
}

vector<int> add(vector<int> a, vector<int> b){
	vector<int> res(max(a.size(), b.size()), 0);
	for(int i=0;i<a.size();i++) res[i] += a[i];
	for(int i=0;i<b.size();i++) res[i] += b[i];
	return res;
}

int getDigit(string &str, int &idx){
	int res = 0;
	while(idx<str.size() && isdigit(str[idx]))
		res = 10*res+str[idx++]-'0';
	return res;
}

vector<int> parseExpr(string&, int&);

vector<int> parseFact(string &str, int &idx){
	vector<int> res(1, 0);
	if(isdigit(str[idx])){
		res[0] = getDigit(str,idx);
	} else if(str[idx]=='x') {
		res.push_back(1);
		idx++;
	} else if(str[idx]=='('){
		idx++;
		res = parseExpr(str, idx);
		idx++;
	}
	if(idx < str.size() && str[idx]=='^'){
		idx++;
		res = pow(res, getDigit(str, idx));
	}
	return res;
}

vector<int> parseTerm(string &str, int &idx){
	vector<int> res(1, 1);
	while(idx < str.size() && str[idx]!='-' && str[idx]!='+' && str[idx]!=')')
		res = mul(res, parseFact(str, idx));
	return res;
}

vector<int> parseExpr(string &str, int &idx){
	vector<int> res(1, 0);
	while(idx < str.size() && str[idx]!=')'){
		bool m = (str[idx]=='-');
		if(str[idx]=='-'||str[idx]=='+') idx++;
		vector<int> vi = parseTerm(str, idx);
		if(m) for(int i=0;i<vi.size();i++) vi[i] *= -1;
		res = add(res, vi);
	}
	return res;
}

void normalize(vector<int> &vi){
	while(!vi.empty() && vi.back() == 0) vi.pop_back();
	if(vi.empty()) return ;
	int g = vi.back();
	for(int i=0;i<vi.size();i++)
		if(vi[i]!=0) g = gcd(g, abs(vi[i]));
	for(int i=0;i<vi.size();i++) vi[i] /= g;
	if(vi.back()<0)
		for(int i=0;i<vi.size();i++) vi[i] *= -1;
}

void print(vector<int> vi){
	for(int i=vi.size()-1;i>=0;i--){
		if(vi[i]==0) continue;
		if(i==0||abs(vi[i])>1){
			if(i==vi.size()-1) printf("%d", vi[i]);
			else               printf("%+d", vi[i]);
		} else if(i!=vi.size()-1){
			if(vi[i]>0) printf("+");
			else        printf("-");
		}
		if(i > 0) printf("x");
		if(i > 1) printf("^%d", i);
	}
	puts("");
}

vector<int> gcm(vector<int> a, vector<int> b){
	while(true){
		normalize(a);
		normalize(b);
		if(a.empty()) break;
		int L = lcm(a.back(), b.back());
		if(a.size() < b.size()) swap(a, b);
		a = mul(a, vector<int>(1, L/a.back()));
		b = mul(b, vector<int>(1, L/b.back()));
		for(int idxA = a.size()-1,idxB = b.size()-1;idxA>=0 && idxB>=0;idxA--,idxB--)
			a[idxA] -= b[idxB];
	}
	return b;
}


int main(){
	string str;
	while(cin >> str){
		if(str == ".") break;
		int idx = 0;
		vector<int> a = parseExpr(str, idx);
		cin >> str;
		idx = 0;
		vector<int> b = parseExpr(str, idx);
		print(gcm(a, b));
	}
}