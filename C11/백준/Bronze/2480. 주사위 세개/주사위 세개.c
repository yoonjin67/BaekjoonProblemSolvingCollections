#include <stdio.h>
int main() {
	int a, b, c;
	int d, e, f;
	d = 10000;
	e = 1000;
	f = 100;
	scanf("%d %d %d", &a, &b, &c);
	
	if (a == b && a == c) {
		printf("%d",d + a * 1000);

	}
	else if (a == b || a == c || b == c) {
		if (a == b) {
			printf("%d", e + a * f);
		}
		else if (a == c) {
			printf("%d", e + a * f);
		}
		else printf("%d", e + c * f);
	
	}
	else if (a != b ||  a != c || b != c) {
		if (a > b && a > c) {
			printf("%d", a*f);
		}
		else if (b > a && b > c) {
			printf("%d", b*f);
		}
		else if (c > a && c > b) {
			printf("%d", c*f);
		}
	}


}