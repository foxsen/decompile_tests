#include<stdio.h>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
char in[20][20];
char ret[20];
int used[20];
int t[20];
int n;
int m;
set<pair<pair<int,int>,string> >S;
int calc(int a,string b,int c){
	if(S.count(make_pair(make_pair(a,c),b)))return 0;
	S.insert(make_pair(make_pair(a,c),b));
	if(a==n)return 1;
//	printf("%d %s %s\n",a,ret,b.c_str());
	for(int i=0;i<n;i++){
		if(used[i])continue;
		int at=0;
		bool ok=true;
		for(int j=0;j<n;j++)t[j]=0;
		for(int j=0;j<m;j++){
			if(t[in[i][j]-'A'])ok=false;
			while(n==at||(b[at]!='?'&&b[at]!=in[i][j])){
				if(at<n&&b[at]!='?')t[b[at]-'A']=1;
				if(at>=n){
					ok=false;break;
				}
				at++;
			}
			at++;
		}
		if(ok){
			used[i]=1;
			ret[a]='A'+i;
			string to="";
			for(int j=0;j<n;j++)t[j]=0;
			for(int j=0;j<m;j++){
				to+=in[i][m-1-j];
				t[in[i][m-1-j]-'A']=1;
			}
			for(int j=0;j<b.size();j++)if(b[j]!='?'&&!t[b[j]-'A']){
				to+=b[j];
			}
			for(int j=to.size();j<b.size();j++)to+='?';
			if(calc(a+1,to,c+(1<<i)))return 1;
			ret[a]=0;
			used[i]=0;
		}
	}
	return 0;
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	n=a;m=b;
	for(int i=0;i<a;i++)scanf("%s",in[i]);
	string s="";
	for(int i=0;i<n;i++)s+="?";
	calc(0,s,0);
	printf("%s\n",ret);
}