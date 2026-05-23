#include<iostream>
using namespace std;
int main(){
  int a=0,b,c,d,n,h=0,jo,ko,i,p[100]={0};
  cin >> n;
  for(i=0;i<n;i++){
    a=0;
    cin >> jo >> ko;
    h=0;
    while(jo!=ko){
      if(jo == 9 && ko == 5){
	p[h]=jo;
	h++;
	break;
      }
      if(jo == 0 && ko!=0){
	p[h]=jo;
	jo++;
	h++;
	a=0;
      }
      if(jo > ko && jo <6){
	p[h]=jo;
	jo--;
	h++;
      }
      if(jo > ko && jo>=6){
	if(jo <= 9){
	  p[h]=jo;
	  jo++;
	  h++;
	}
	if(jo > 9){
	  jo=5;
	  p[h]=jo;
	  jo--;
	  h++;
	  a=1;
	}
      }
      if(jo < ko && a!=1){
	p[h]=jo;
	jo++;
	h++;
      }
      if(jo < ko && a==1){
	p[h]=jo;
	jo--;
	h++;
      }
    }
    for(d=0;d<h;d++){
      cout << p[d] << " " ;
    }
    cout << ko << endl;
  }
}