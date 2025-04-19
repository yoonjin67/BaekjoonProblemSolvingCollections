#include<stdio.h>
#include<ctype.h>
#include<string.h>
void to_lower(int i)
{
  auto char namelist[i][21];
  auto int x;
  for(x=0;x<i;x++)
  {
    scanf("%s",namelist[x]);
    auto int n;
    for(n=0;n<strlen(namelist[x]);n++)
    {
       if(65<=namelist[x][n]&&namelist[x][n]<=90)
         namelist[x][n]=tolower(namelist[x][n]);
    }
    printf("%s\n",namelist[x]);
  }
}
int main()
{
  auto int i;
  scanf("%d",&i);
  to_lower(i);
  return 0;
}