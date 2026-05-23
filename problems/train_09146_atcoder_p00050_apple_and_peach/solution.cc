#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	int len;
	char str[1024];
	
	fgets(str, 1024, stdin);
	
	len = strlen(str);
	for (i = 0; i < len; i++){
		if (strncmp(&str[i], "apple", 5) == 0){
			strncpy(&str[i], "peach", 5);
		}
		else if (strncmp(&str[i], "peach", 5) == 0){
			strncpy(&str[i], "apple", 5);
		}
	}
	printf("%s", str);
	
	return (0);
}