#include<stdio.h>
#include<string.h>

int main() {
    int n;
    scanf("%d",&n);
    char reg[101], head[101], tail[101];
    memset(reg,0,sizeof(reg));
    memset(head,0,sizeof(head));
    memset(tail,0,sizeof(tail));
    scanf("%s\n",reg);
    int i;
    for(i = 0; i < strlen(reg); i++) {
        if(reg[i] == '*') break;
        if('a' <= reg[i] && reg[i] <= 'z') 
            head[i] = reg[i];
        else
            break;
    }
    i++;
    for(int j = 0;i < strlen(reg); i++,j++) {
        if('a' <= reg[i] && reg[i] <= 'z') 
            tail[j] = reg[i];
        else
            break;
    }
    for(int i = 0; i < n; i++) {
        char str[101];
        char str_head[101];
        scanf("%s",str);
        getchar();
        if(strlen(str)<(strlen(head)+strlen(tail))) {
            puts("NE");
            continue;
        }
        if(!strncmp(str,head,strlen(head)) && !strncmp(tail,str+(strlen(str)-strlen(tail)),strlen(tail))) {
            puts("DA");
        } else {
            puts("NE");
        }
    }
    return 0;
}