#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b) {
	return *(int *)b-*(int *)a;
}
int main() {
	int N;
	scanf("%d", &N);
	int array[N];
	int i;
	for(i=0;i<N;i++) {
		scanf("%d", array+i);
	}
	qsort(array,N,sizeof(int),compare);
	for(i=0;i<N;i++) {
		printf("%d\n",array[i]);
	}
	return 0;
}
