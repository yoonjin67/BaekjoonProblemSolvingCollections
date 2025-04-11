#include <stdio.h>
#include<string.h>

int main() {
	int LEN=5,i;
	char str[LEN], str2[LEN];
	scanf("%s", str);
    if(!strncmp(str,"0",1)) {
        return 0;
    }
	LEN=strlen(str);
	for(i=0;i<LEN;i++) {
		str2[i]=str[LEN-i-1];
	}
	puts(strncmp(str,str2,LEN)==0?"yes":"no");
	return main();
	
}