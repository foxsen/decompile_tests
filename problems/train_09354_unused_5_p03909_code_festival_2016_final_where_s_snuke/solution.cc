#include <stdio.h>
#include <string.h>
int main()
{
	int h,w;
	char c[10];
	scanf("%d %d",&h,&w);
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			scanf("%s",c);
			if(c[0]=='s'&&c[1]=='n'&&c[2]=='u'&&c[3]=='k'&&c[4]=='e'){
				printf("%c%d",'A'+j,i+1);
				return 0;
			}
		}
	}
}