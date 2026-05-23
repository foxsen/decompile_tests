#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s[11111],t;
int n;

int F(string a,string b){
	bool ok[2]={0,0};
	for(int i=0;i<a.size();i++){
		if(i==b.size()){ok[0]=1;break;}
		if(a[i]=='?')if('z'>b[i]){ok[0]=1;break;}
		if(a[i]>b[i]){ok[0]=1;break;}
		if(a[i]<b[i])break;
	}//大きい可能性

	for(int i=0;i<a.size();i++){
		if(i==b.size()){break;}
		if(a[i]=='?')if('a'<b[i]){ok[1]=1;break;}
		if(a[i]<b[i]){ok[1]=1;break;}
		if(a[i]>b[i])break;
		if(i==a.size()-1&&b.size()>a.size()){ok[1]=1;break;}
	}//小さい可能性

	if(ok[0]&&ok[1])return 2;
	if(!ok[0]&&ok[1])return 1;
	if(ok[0]&&!ok[1])return 0;
	return 2;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	cin>>t;
	int a=0,b=0,c;
	for(int i=0;i<n;i++){
		c=F(s[i],t);
		if(c==1)a++;
		if(c==2)b++;
	}
	bool f=0;
	for(int i=a;i<=a+b;i++){
		if(f)cout<<" ";
		f=1;
		cout<<i+1;
	}
	cout<<endl;
	return 0;
}