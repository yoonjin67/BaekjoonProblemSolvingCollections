#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    unsigned short N;
    scanf("%hu",&N);
    unsigned short K[N], j=0, i,len;
    memset(K,0,sizeof(unsigned short int)*N);
    scanf("%hu",&len);
    if(len==1) {
        printf("1");
        return 0;
    }
    for(i=1;j<=len && i<=N ;i++) {
        if(!(N%i)) {
            K[j]=i;
            j++;
        }
    }

    printf("%hu", K[len-1]);
    return 0;

}