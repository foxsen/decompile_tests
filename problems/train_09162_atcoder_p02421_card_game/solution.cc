#include <iostream>
#include <string>
using namespace std;
int main(){

int i,n,t=0,h=0;
string tc,hc;

cin>>n;

for(i=0; i<n; i++){

cin>>tc>>hc;

if(tc>hc)t+=3;
else if(tc<hc)h+=3;
else{
t++;
h++;
}

}

cout<<t<<" "<<h<<"\n";

}