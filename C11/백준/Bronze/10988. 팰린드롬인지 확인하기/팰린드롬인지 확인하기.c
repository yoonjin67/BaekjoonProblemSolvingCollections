#include <stdio.h>
#include<string.h>

int main() {
	int LEN=101,i;
	char str[LEN], str2[LEN];
	scanf("%s", str);
	LEN=strlen(str);
	for(i=0;i<LEN;i++) {
		str2[i]=str[LEN-i-1];
	}
	printf("%s",strncmp(str,str2,LEN)==0?"1":"0");
	return 0;
	
}