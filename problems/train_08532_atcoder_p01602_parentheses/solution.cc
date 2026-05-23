#include <iostream>

using namespace std;

int main(){

    long long int n,a=0,tmp;
    char p;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p>>tmp;
        if(p=='('){
            a+=tmp;
        }else{
            a-=tmp;
        }
        if(a<0){
             cout<<"NO"<<endl;
             return 0;
        }
    }
    if(a==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
