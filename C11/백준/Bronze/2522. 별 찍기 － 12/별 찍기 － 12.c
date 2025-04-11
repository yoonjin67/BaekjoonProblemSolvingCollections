#include<stdio.h>
main() {
	int X,i,j;
	scanf("%d",&X);
	for(j=1;j<=X;j++) {
		for(i=j;i<X;i++) {
			putchar(' ');
		}
		for(i=0;i<j;i++) {
			putchar('*');
		}
		putchar('\n');
	}
	for(j=X-1;j>=1;j--) {
		for(i=j;i<X;i++) {
			putchar(' ');
		}
		for(i=0;i<j;i++) {
			putchar('*');
		}
		putchar('\n');
	}
	return 0;
}