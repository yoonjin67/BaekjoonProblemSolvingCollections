void star(short x)
{
        register short i,ii;
        for(i=x-1;i>=0;i--)
                {
                for(ii=0;ii<i;ii++,printf(" "));
                for(ii=0;ii<x-i;ii++,printf("*"));
                printf("\n");
                }
}
int main()
{
        short num;
        scanf("%hd", &num);
        star(num);
        return 0;
}
