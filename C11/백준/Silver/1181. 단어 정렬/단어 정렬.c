#include <stdio.h>
#include <string.h>
int compare(const void *a, const void *b) {
		if(!(strlen((char*)a)-strlen((char*)b))) {
			if(strcmp((char *)a,(char *)b)==0) {
					memset(b,0,sizeof(char)*51);
			        return 0;
			}
		    return (strcmp((char *)a,(char *)b)>0?1:0);
		}
		return strlen((char*)a)-strlen((char*)b);
}
int main() {
		int len;
		scanf("%d",&len);
		char str[len][51];
		char empty[51];
		memset(empty,0,51);

		int i;
		for(i=0;i<len;i++) {
				scanf("%s",str+i);
		}

		qsort(str,len,sizeof(char)*51,compare);
		for(i=0;i<len;i++) {
				if(strlen(str[i])==0) {
						continue;
				}
				printf("%s\n",str[i]);
		}
		return 0;
}



