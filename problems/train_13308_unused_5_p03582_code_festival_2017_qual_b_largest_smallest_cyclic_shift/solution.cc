#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<set>
using namespace std;
#define REP(i,st,ed) for(int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(int i=st,i##end=ed;i>=i##end;--i)
multiset<string>s;
multiset<string>::iterator it1,it2;
int a,b,c;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	REP(i,1,a)s.insert("a");
	REP(i,1,b)s.insert("b");
	REP(i,1,c)s.insert("c");
	REP(i,1,a+b+c-1){
		it1=s.begin();
		it2=s.end(),--it2;
		s.insert(*it1+*it2);
		s.erase(it1);
		s.erase(it2);
	}
	cout<<*s.begin()<<endl;
	return 0;
}