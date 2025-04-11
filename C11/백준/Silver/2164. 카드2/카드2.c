#include <stdio.h>
int main()
{
	int i, n, front=0, rear;
	scanf("%d", &n);
    int queue[n];	
	for(i=0; i<n; i++) 
        queue[i]=i+1;
	rear=n-1;
	
	while(1) {
		front=(front+1)%n;
		if(rear==front) break; 
		rear=(rear+1)%n;
		queue[rear]=queue[front];
		front=(front+1)%n;
		if(rear==front) break; 
	}
	printf("%d", queue[rear]); 
	return 0;
}