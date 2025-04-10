#include<string.h>
#include<stdbool.h>
#include<stdio.h>
static int array[20];
void chkIdx(int x, bool flag) {
    if(!flag) {
        printf("%d\n",array[x-1]);
    } else {
        array[x-1]=!array[x-1];
    }
}
int main() {

    int tasks,num;
    scanf("%d",&tasks);
    for(int i=0;i<tasks;i++) {
        char cmd[7];
        scanf("%s",cmd);
        if(!strncmp("add",cmd,3)) {
            scanf("%d",&num);
            array[num-1]=1;
        } else if(!strncmp("remove",cmd,6)) {
            scanf("%d",&num);
            array[num-1]=0;
        } else if (!strncmp("check",cmd,5)) {
            scanf("%d",&num);
            chkIdx(num,false);
        } else if(!strncmp("toggle",cmd,6)) {
            scanf("%d",&num);
            chkIdx(num,true);
        } else if(!strncmp("empty",cmd,5)) {
            memset(array,0,sizeof(int)*20);
        } else {
            for(int i=1;i<=20;i++) {
                array[i-1]=1;
            }
        }
    }
    return 0;
}