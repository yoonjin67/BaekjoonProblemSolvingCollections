#include<stdio.h>
int main(){
        short money=1000, val, count=0,i;
        short arr[]={500,100,50,10,5,1};
        scanf("%hd", &val);
        money-=val;
        for (i=0;i<6;i++){
                for (;money-arr[i]>=0;) {
                        money-=arr[i];
                        count++;
                }
        }
        printf("%hd", count);
        return 0;
}
