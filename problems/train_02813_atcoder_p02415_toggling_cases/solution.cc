#include<stdio.h>
#include<wctype.h>
#include<ctype.h>

int main()
{
	char sent[1200];
	int x;
	gets(sent);
	for (x = 0; sent[x] != '\0'; x++)
	{
		if (isupper(sent[x]))
		{
			sent[x] = tolower(sent[x]);
		}
		else
		{
			sent[x] = toupper(sent[x]);
		}
	}
	puts(sent);
	return 0;
}