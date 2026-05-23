#include<cstdio>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<int> expr();
vector<int> set1();
vector<int> set2();
vector<int> alpha();

int idx;
char s[2000];

vector<int> S[5],U;

vector<int> calc_c(const vector<int> &A){
	vector<int> B;
	rep(i,U.size()) if(!binary_search(A.begin(),A.end(),U[i])) B.push_back(U[i]);
	return B;
}

vector<int> calc_u(const vector<int> &A,const vector<int> &B){
	vector<int> C;
	rep(i,A.size()) C.push_back(A[i]);
	rep(i,B.size()) C.push_back(B[i]);
	sort(C.begin(),C.end());
	C.erase(unique(C.begin(),C.end()),C.end());
	return C;
}

vector<int> calc_i(const vector<int> &A,const vector<int> &B){
	return calc_c(calc_u(calc_c(A),calc_c(B)));
}

vector<int> calc_d(const vector<int> &A,const vector<int> &B){
	return calc_i(A,calc_c(B));
}

vector<int> calc_s(const vector<int> &A,const vector<int> &B){
	return calc_u(calc_d(A,B),calc_d(B,A));
}

vector<int> expr(){
	vector<int> A=set1();
	while(s[idx] && s[idx]!=')'){
		char op=s[idx++];
		vector<int> B=set1();

		if     (op=='u') A=calc_u(A,B);
		else if(op=='i') A=calc_i(A,B);
		else if(op=='d') A=calc_d(A,B);
		else             A=calc_s(A,B);
	}
	return A;
}

vector<int> set1(){
	if(s[idx]=='c'){
		idx++;
		return calc_c(set1());
	}
	else return set2();
}

vector<int> set2(){
	vector<int> A;
	if(s[idx]=='('){
		idx++;
		A=expr();
		idx++;
	}
	else A=alpha();
	return A;
}

vector<int> alpha(){ return S[s[idx++]-'A']; }

int main(){
	while(1){
		U.clear();
		while(1){
			char c;
			int n;
			if(!~scanf(" %c%d",&c,&n)) return 0;
			if(c=='R') break;

			S[c-'A'].clear();
			rep(i,n){
				int e; scanf("%d",&e);
				S[c-'A'].push_back(e);
				U.push_back(e);
			}
			sort(S[c-'A'].begin(),S[c-'A'].end());
		}
		sort(U.begin(),U.end());
		U.erase(unique(U.begin(),U.end()),U.end());

		scanf("%s",s);
		idx=0;
		vector<int> res=expr();

		if(res.size()==0) puts("NULL");
		else rep(i,res.size()) printf("%d%c",res[i],i<(int)res.size()-1?' ':'\n');
	}
}