#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(const void *a, const void *b) {
    return strcmp((char*)a,(char*)b);
}

int main() {
    char str[1001];
    scanf("%s",str);
    
    int i;
    int len = strlen(str);
    
    char strSet[len][1001];
    memset(strSet,0,len*1001);
    
    for(i=0;i<len;i++) {
        strncpy(strSet[i],str+i,strlen(str)-i);
    }
    
    qsort(strSet,len,sizeof(char)*1001,compare);
    
    for(i=0;i<len;i++) {
        if(strlen(strSet[i])) {
            puts(strSet[i]);
        }
    }
    return 0;
}
