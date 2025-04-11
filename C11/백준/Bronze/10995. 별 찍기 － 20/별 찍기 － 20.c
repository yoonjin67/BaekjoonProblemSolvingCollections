#include<stdio.h>
main() {
	int X,i,j;
	int odd=0;
	scanf("%d",&X);
	for(i=0;i<X;i++) {
		odd = i%2;
		if(odd) {
			for(j=0;j<X*2;j++) {
				putchar(j%2==0?' ':'*');
			}
		} else {
			for(j=0;j<X*2-1;j++) {
				putchar(j%2==0?'*':' ');
			}
		}
		putchar('\n');
	}
	return 0;
}