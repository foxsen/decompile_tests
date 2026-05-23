#include <iostream>
#include <stdio.h>
using namespace std;
int pr[1000003];
int main() {
 int i,j,n,p,m,f,e,g;
 for (i=2;i<1000000;i++) if (pr[i]==0) { pr[i]=2; for (j=i*2;j<1000000;j+=i) pr[j]=1;}
 for (i=2,j=0;i<1000000;i++) { j+=pr[i]>1; pr[i]=j; }
 while(cin >> n) {
	 if (n==0) break;
	 g=0;
	 for (;n>0;n--) {
      cin >> p >> m;
	  f=p-m<0 ? 0 : p-m;
	  e=p+m>999999 ? 999999 : p+m;
	  j=pr[e]-pr[f-1];
	  if (j==0) g--;  else g+=j-1;
	 }
	 cout << g << endl;
 }
 return 0;
 }