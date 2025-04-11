#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 10
int compare(const void *a,const void *b) {
		return *(char *)b-*(char *)a;
}
int main() {
		char myString[LEN+1];
        memset(myString,0,LEN+1);
		scanf("%s", myString);
        if(strlen(myString)>1)
		    qsort(myString,LEN,sizeof(char),compare);
		printf("%s",myString);
		return 0;
}

		
