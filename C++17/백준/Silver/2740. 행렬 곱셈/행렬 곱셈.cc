#include<stdio.h>

int main() {
    int n,m;
    scanf("%d %d", &n,&m);
    int matrix1[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d",&matrix1[i][j]);
        }
    }
    int k;
    scanf("%*d %d", &k);
    int matrix2[m][k];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            scanf("%d",&matrix2[i][j]);
        }
    }
    int res[n][k];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            res[i][j] = 0;
            for(int l = 0; l < m; l++) {
                res[i][j] +=
                    matrix1[i][l]*
                    matrix2[l][j];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            printf("%d ", res[i][j]);
        }
        puts("");
    }
    return 0;
}