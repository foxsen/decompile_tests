#import<iostream>
using namespace std;
string s;int c,f;
int main(){
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='S')f++;
    else if(f>0)f--,c+=2;
  }
  cout<<s.size()-c<<endl;
}