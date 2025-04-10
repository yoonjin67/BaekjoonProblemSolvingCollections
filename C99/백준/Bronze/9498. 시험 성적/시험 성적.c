int main()
{
short x;
scanf("%hd", &x);
if(90<=x & x<=100)
        puts("A");
else if(80<=x & x<90)
        puts("B");
else if(70<=x & x<80)
        puts("C");
else if(60<=x & x<70)
        puts("D");
else
        puts("F");
return 0;
}
