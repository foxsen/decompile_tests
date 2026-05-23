#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

map<char,char>mp[26][26];
int main(){
	for(int i=1;i<26;i+=2){
		rep(j,26){
			rep(k,26){
				mp[i/2][j][(k*i+j)%26+'a']=k+'a';
			}
		}
	}
	int n;scanf("%d\n",&n);
	rep(i,n){
		p:;
		string s;getline(cin,s);
		rep(i,26/2){
			rep(j,26){
				string copy=s;
				for(char&c:copy){
					if(isalpha(c)){
						c=mp[i][j][c];
					}
				}
				if((int)copy.find("this")>=0||(int)copy.find("that")>=0){
					cout<<copy<<endl;
					goto p;
				}
			}
		}
	}
}