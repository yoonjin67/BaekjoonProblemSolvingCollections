#include<stdio.h>
#include<stdlib.h>
typedef struct name {
	char name[16];
	int  day;
	int  month;
	int  years;
} _name;
int compare(const void *a, const void *b) {
	_name A = *(const _name *)a;
	_name B = *(const _name *)b;

	if(A.years!=B.years) {
		return B.years-A.years;
	} else if(A.month!=B.month) {
		return B.month-A.month;
	} else {
		return B.day-A.day;
	}
}
int main() {
	int N;
	scanf("%d", &N);
	_name array[N];
	int i;
	for(i=0;i<N;i++) {
		scanf("%s %d %d %d", array[i].name, &array[i].day, &array[i].month, &array[i].years);
	}
	qsort(array,N,sizeof(_name),compare);
	puts(array[0].name);
	puts(array[N-1].name);
	return 0;
}
