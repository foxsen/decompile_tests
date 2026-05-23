//41
#include<iostream>
#include<vector>

using namespace std;

int main(){
  for(;;){
    vector<int> num(10);
    for(int i=0;i<10;i++){
      char c;
      if(!(cin>>c))return 0;
      num[i]=c-'0';
    }
    while(num.size()!=1){
      vector<int> temp;
      for(int i=1;i<num.size();i++){
	temp.push_back((num[i-1]+num[i])%10);
      }
      num=temp;
    }
    cout<<num[0]<<endl;
  }
  return 0;
}