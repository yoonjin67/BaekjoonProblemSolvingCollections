#include<stdio.h>
int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = n - i; j > 1; j--)
		{
			printf(" ");
		}
		for (j = 1; j <= 1 * i + 1; j++)
		{
			if (n == 1) {
				printf("*");
				return 0;
			}
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}