#include <stdio.h>
#include <string.h>
int main()
{
    char a,b[51],c;
    int i,j,flag,size;
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
        flag=1;
        a=0;
        scanf("%s", b);
        size=strlen(b);
        int k=0;
        while(k<size)
        {
             c=b[k];
             if(c=='(')
                 a++;
             else if(c==')')
             {
                 a--;
                 if(a<0)
                     flag=0;
             }
             k++;
        }
        if(a==0 & flag==1)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
