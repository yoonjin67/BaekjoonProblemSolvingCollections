#include<stdio.h>
#include<string.h>
int dialCollectCall(char dial) {
	if ('A'<=dial && dial <='C') {
		return 3;
	}
	else if('D' <=dial && dial <= 'F') {
		return 4;
	}
	else if('G'<=dial && dial<='I') {
		return 5;
	}
	else if('J'<=dial&& dial<='L') {
		return 6;
	}
	else if('M'<=dial &&dial<='O') {
		return 7;
	}
	else if('P'<=dial&&dial<='S') {
		return 8;
	}
	else if('T'<=dial&& dial<='V') {
		return 9;
	}
	else if('W'<=dial&& dial<='Z') {
		return 10;
	}
}
int main() {
	char dial[16];
	memset(dial,0,sizeof(dial));
	scanf("%s", dial);
	int sum = 0, i;
	for(i=0;i<strlen(dial);i++) {
		sum+=dialCollectCall(dial[i]);
	}
	printf("%d", sum);
	return 0;
}

