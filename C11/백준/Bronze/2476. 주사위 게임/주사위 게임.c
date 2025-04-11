#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(const void *a, const void *b) {
	return *(int*)a-*(int*)b;
}
int main() {
	int REPEAT;
	
	scanf("%d",&REPEAT);
	int resultArr[REPEAT];
	for(auto int i=0;i<REPEAT;i++) {
		int internalArr[3];
		scanf("%d %d %d", internalArr, internalArr+1, internalArr+2);
		qsort(internalArr,3,sizeof(int),compare);
		if(internalArr[1]==internalArr[0] && internalArr[1] == internalArr[2]) {
			resultArr[i]=10000+internalArr[0]*1000;
		} else if (internalArr[1]==internalArr[0]) {
			resultArr[i]=1000+internalArr[0]*100;
		} else if (internalArr[1]==internalArr[2]) {
			resultArr[i]=1000+internalArr[2]*100;
		} else {
			resultArr[i]= internalArr[2]*100;
		}


	}
	qsort(resultArr, REPEAT, sizeof(int), compare);
	printf("%d", resultArr[REPEAT-1]);
	
	return 0;
}



				
	       				

       	

