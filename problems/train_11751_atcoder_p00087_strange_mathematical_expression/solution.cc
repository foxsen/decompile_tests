#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<cstdlib>
using namespace std;
int main(){
  string r;
  while(getline(cin,r)){
    r+=' ';
    int mark = -1,range = 1;
    stack <double> num;
    char ord = 'k';
    for(int i=0; i<r.size(); i++){
      if(r[i] == ' '){
	if(mark != -1){
	  double x = atof(r.substr(mark,range).c_str());
	  if(ord == '-'){x = -x;ord = 'k';}
	  num.push(x);
	  mark = -1;
	  range = 1;
	}
	else{
	  double a = num.top();
	  num.pop();
	  double b = num.top();
	  num.pop();
	  if(ord == '+'){num.push(b+a);}
	  if(ord == '-'){num.push(b-a);}
	  if(ord == '/'){num.push(b/a);}
	  if(ord == '*'){num.push(b*a);}
	  ord = 'k';
	}
      }
      else if((r[i]>='0' && r[i]<='9') || r[i] == '.'){
	if(mark == -1){mark = i;}
	else{range++;}
      }
      else{ord = r[i];}
    }
    printf("%.6lf\n",num.top());
  }
  return 0;
}