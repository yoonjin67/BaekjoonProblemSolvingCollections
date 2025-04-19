#include<stdio.h>
#include <unistd.h>
int main()
{
unsigned long x;
scanf("%lu", &x);
char w[2];
    memcpy(w,((!(x%7)|!((x%7)^2))?"CY":"SK"),sizeof(char)*2);
    write(STDOUT_FILENO,w,2);
return 0;
}


