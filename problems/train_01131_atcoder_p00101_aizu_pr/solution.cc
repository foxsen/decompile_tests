#include <iostream>
#include <cstring>
using namespace std;
int main(){
int n,len;
string a;
cin>>n;
getline(cin,a);
for(int i=0;i<n;i++){
getline(cin,a);
len=a.size();
for(int o=0;o<=len;o++)
if(a[o]=='H'){
if(a[o+1]=='o')
if(a[o+2]=='s')
if(a[o+3]=='h')
if(a[o+4]=='i')
if(a[o+5]=='n')
if(a[o+6]=='o')
a[o+6]='a';}
cout<<a<<endl;}
return 0;
}