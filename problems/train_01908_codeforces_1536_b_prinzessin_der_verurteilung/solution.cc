#include <bits/stdc++.h>
 
using namespace std; /*string::npos*/
int gcd(int a, int b){
  if (a == 0)
        return b;
    return gcd(b % a, a);
       
}
int main(){
 
	int t;
	cin>>t;
	while(t--)
{int n;
cin>>n;
string str;
cin>>str;
int arr[26]={0};
int c=0;
for(int i=0;i<str.length();i++){
       arr[str[i]-97]++;
       if(arr[str[i]-97]==1) c++;
}
string s="";
if(c<26){
       for(int i=0;i<26;i++){
              if(arr[i]==0)
              {s=s+(char)(i+97); break;}
       }
       cout<<s<<endl;
}
else{
       char z='a';
       for(char ch='a';ch<='z';ch++){
              for(char k='a';k<='z';k++){
                     string t="";
                     t+=ch;t+=k;
                     int index;
                     if((index = str.find(t,0)) == string::npos){
                            cout<<t<<endl;
                            ch='z';z='b';
                            break;
                     }
              }
       }
       for(;z<'b';z++){
              for(char ch='a';ch<='z';ch++){
              for(char k='a';k<='z';k++){
                     string t="";t+=z;
                     t+=ch;t+=k;
                     int index;
                     if((index = str.find(t,0)) == string::npos){
                            cout<<t<<endl;
                            ch='z';z='b';
                            break;
                     }
              }
       }
       }
    
}

       
       
       
       
       
       
}
	return 0;     // Writing output to STDOUT
}