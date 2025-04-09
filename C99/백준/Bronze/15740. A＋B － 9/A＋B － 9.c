#include<string.h>
#include<stdlib.h>
#include<stdio.h>
void swap(void *a,void *b, int n)
{
    void *t=malloc(n);
    memcpy(t,a,n);
    memcpy(a,b,n);
    memcpy(b,t,n);
}
typedef long long ll;
int am,bm,al,bl,il;
char a[10001],b[10001],c,out[10002],in[10002];
int main(){
    scanf(" %s",in);
    il=strlen(in);
    if(in[0]=='-'){
        am=1;
        for(int i=1;i<il;i++) a[i-1]=in[i];
    }else{
        for(int i=0;i<il;i++) a[i]=in[i];
    }
    al=strlen(a);

    scanf(" %s",in);
    il=strlen(in);
    if(in[0]=='-'){
        bm=1;
        for(int i=1;i<il;i++) b[i-1]=in[i];
    }else{
        for(int i=0;i<il;i++) b[i]=in[i];
    }
    bl=strlen(b);

    if(al<bl){ swap(&al,&bl,sizeof(al));swap(a,b,sizeof(a));swap(&am,&bm,sizeof(am));}
    else if(al==bl){
        int fl=0;
        for(int i=0;i<=al;i++){
            if(i==al){
                fl=1;
                break;
            }
            if(a[i] < b[i]){swap(&al,&bl,sizeof(al));swap(a,b,sizeof(a));swap(&am,&bm,sizeof(am)); break;}
            else if(a[i] > b[i]) break;
        }
        if(am != bm && fl) return !printf("0");
    }


    if(am) printf("-");

    if(am != bm){
        int fl=0;
        for(int i=1;i<=al;i++){
            out[al-i] = a[al-i]-fl;
            if(i<=bl) out[al-i] += '0' - b[bl-i];
            if(out[al-i] < '0'){
                out[al-i]+=10;
                fl=1;
            }else fl=0;
        }
        int j=0;
        while(j<al-1 && out[j] == '0') j++;
        printf("%s",out+j);
    }else{
        int fl=0;
        for(int i=1;i<=al;i++){
            out[al-i] = a[al-i]+fl;
            if(i <= bl) out[al-i] += b[bl-i] - '0';
            if(out[al-i] > '9'){
                out[al-i]-=10;
                fl=1;
            }else fl=0;
        }
        if(fl) printf("1");
        printf("%s",out);
    }
}

