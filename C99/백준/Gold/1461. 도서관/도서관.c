#include <math.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (int)*(int *)a-*(int *)b;
}


int main () {

    static int N,M;
    scanf("%d %d", &N,&M);
    int i;
    auto int res=0;
    auto int books[N+1], flag;
    for (i=0;i<N;i++) {
        scanf("%d", books+i);
    }
    books[N]=0;
    qsort(books,N+1,sizeof(int),compare);
    for( flag=0;books[flag]!=0;flag++);
    for (i=0;i<flag;i++) {
        if(!(i%M))
            res-=2*books[i];
    }
    for(i=N;i>flag;i--) {
        if(!((N-i)%M))
            res+=2*books[i];
    }
    if(abs(books[0])>abs(books[N])) {
        res+=books[0];
    } else {
        res-=books[N];
    }
    printf("%d",res);
    return 0;
}
