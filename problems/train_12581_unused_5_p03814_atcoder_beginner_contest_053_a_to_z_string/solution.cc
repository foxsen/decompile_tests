#include <iostream>
#include <string>

using namespace std;

int main(){
  string S; cin>>S;

  cout<<S.rfind('Z')-S.find('A')+1<<endl;

  return 0;
}
