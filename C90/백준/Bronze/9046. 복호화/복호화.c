#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ALPHA_LEN (int)('z'-'a')+1

typedef struct alphabet {
        int vol;
        char c;
} alphabet;

int comp(const void *a, const void *b) {
        alphabet ap_1 = *(alphabet *)a, ap_2 = *(alphabet *)b;
        return ap_2.vol - ap_1.vol;
}

alphabet alphabets[ALPHA_LEN];

int main() {
        char str[256];
        int n;
        int i;
        int j;
        scanf("%d\n",&n);
        for(i = 0; i < n; i++) {
                memset(alphabets,0,sizeof(alphabets));
                scanf("%[^\n]",str);
                getchar();
                for(j = 0; j < strlen(str); j++) {
                        if(str[j] != ' ' && 'a' <= str[j] && str[j] <= 'z') {
                                alphabets[str[j]-'a'].vol++;
                                alphabets[str[j]-'a'].c = str[j];
                        }
                }
                qsort(alphabets,ALPHA_LEN,sizeof(alphabet),comp);
                if(alphabets[0].vol == alphabets[1].vol) puts("?");
                else printf("%c\n",alphabets[0].c);
        }
        return 0;
}