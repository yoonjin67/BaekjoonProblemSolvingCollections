int factorial(int x)
{
    register int i;
    if(x==0)
        return 1;
    else
    {    
        register int ii=1;
        for(i=x;i>0;ii*=i,i--);
        return ii;
    }
}
int main()
{
    int num;
    scanf("%d", &num);
    num=factorial(num);
    printf("%d",num);
    return 0;
}