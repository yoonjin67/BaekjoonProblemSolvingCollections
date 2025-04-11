#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
const size_t SIZEOF_CHAR = sizeof(char);
typedef struct meeting {
  int start;
  int end;
} meeting;
const size_t SIZEOF_MEETING = sizeof(meeting);
int comp(const void *a, const void *b) {
  meeting *x = (meeting *)a;
  meeting *y = (meeting *)b;
  if(x->end==y->end) {
    return x->start-y->start;
  }
  return x->end-y->end;
}
void print(int n) {
    int i=n,count=0,y=0;
    while(i!=0)
    {
        i/=10;
        ++count;
    }
    char x[count+1];
    x[count]='\0';
    count--;
    while(count>=0)
    {
        y=n%10;
        x[count]=y+48;
        n=n/10;
        count--;
    }
    y=0;
    while(x[y]!='\0')
    {
       fwrite(&x[y],SIZEOF_CHAR,1,stdout);
       y++;
    }
}

void input_integer(int *n)
{
    static int c;

    *n = getchar_unlocked() - '0';
    while (isdigit((c = getchar_unlocked())))
        *n = 10*(*n) + c-'0';
}
int main() {
  int answer = 0;
  int n;
  int i;
  int x,y;
  meeting *m = malloc(SIZEOF_MEETING);
  int m_len = 0;
  int endtime=0;
  input_integer(&n);
  for(i = 0; i < n; i++) {
    input_integer(&x);
    input_integer(&y);
    m_len++;
    m = (meeting *) realloc(m,SIZEOF_MEETING*m_len);
    m[m_len-1] = (meeting){
      .start = x,
      .end = y
    };
  }
  qsort(m,m_len,SIZEOF_MEETING,comp);
  for(i = 0; i < m_len; i++) {
    if(endtime<=m[i].start) {
      endtime = m[i].end;
      answer++;
    }
  }
  print(answer);
  free(m);
  fflush(stdout);
  fflush(stdin);
  return 0;
}
