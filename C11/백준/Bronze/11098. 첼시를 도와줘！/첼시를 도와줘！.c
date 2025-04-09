#include<stdio.h>
#include<stdlib.h>
typedef struct soccerMem {
	int price;
	char name[21];
} sMem;
int compare(const void *a, const void *b) {
	sMem A = *(sMem *)a;
	sMem B = *(sMem *)b;
	return B.price - A.price;
}
int main() {
	int N;
	scanf("%d", &N);
	int i,j;
	int X;
	sMem *array;
	for(i=0;i<N;i++) {
		scanf("%d", &X);
		array = malloc(sizeof(sMem)*X);
		for(j=0;j<X;j++) {
			scanf("%d %s", &array[j].price, array[j].name);
		}
		qsort(array,X,sizeof(sMem),compare);
		puts(array[0].name);
	}
}
