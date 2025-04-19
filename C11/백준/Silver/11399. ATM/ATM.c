#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b){
	return (*(int *)a-*(int *)b);
}

int __sum__(int *arr, int j) {
	int i;
	int sum=0;
	for (i=0;i<j;i++) {
		sum+=arr[i];
	}
	return sum;
}

int main() {
	int N,i, sum=0;
	scanf("%d", &N);
	int arr[N];
	for (i=0;i<N;i++) {
		scanf("%d", arr+i);
	}
	qsort(arr, N, sizeof(int), compare);
	for (i=0;i<N;i++) {
		sum+=__sum__(arr, i+1);
	}
	printf("%d", sum);
	return 0;
}
