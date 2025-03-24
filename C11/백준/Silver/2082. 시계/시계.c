#include <stdio.h>
#include <limits.h>

char digits5x3[10][5][3] = {
    {
        "###", "#.#", "#.#", "#.#", "###"
    },
    {
        "..#", "..#", "..#", "..#", "..#"
    },
    {
        "###", "..#", "###", "#..", "###"
    },
    {
        "###", "..#", "###", "..#", "###"
    },
    {
        "#.#", "#.#", "###", "..#", "..#"
    },
    {
        "###", "#..", "###", "..#", "###"
    },
    {
        "###", "#..", "###", "#.#", "###"
    },
    {
        "###", "..#", "..#", "..#", "..#"
    },
    {
        "###", "#.#", "###", "#.#", "###"
    },
    {
        "###", "#.#", "###", "..#", "###"
    }
};

int compareDigits(char a1[5][3]) {
    int cmin = INT_MAX;
    int ret = -1;
    for (int v = 0; v < 10; v++) {
        int pix = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                if (a1[i][j] == '#' && digits5x3[v][i][j] != a1[i][j]) {
                    pix++;
                }
            }
        }
        if (cmin >= pix) {
            if(cmin == pix){
                if(ret > v || ret == -1) ret = v;
            } else {
                ret = v;
            }
            cmin = pix;
        }
    }
    return ret;
}

int main() {
    char input[4][5][3];
    char line[100];
    int min_h1 = 2, min_h2 = 9, min_m1 = 5, min_m2 = 9;

    for (int i = 0; i < 5; i++) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            return 1; // 입력 오류 처리
        }
        // line의 입력값이 제대로 4개의 값으로 나뉘어지지 않으면 오류 반환
        if (sscanf(line, "%3s %3s %3s %3s", input[0][i], input[1][i], input[2][i], input[3][i]) != 4) {
            return 1; // 입력 오류 처리
        }
    }

    // 각 시간을 조합하여 최소 시간 값을 찾기
    for (int h1 = 0; h1 <= 2; h1++) {
        for (int h2 = 0; h2 <= 9; h2++) {
            if (h1 == 2 && h2 > 3) continue; // 24시 제한 조건
            for (int m1 = 0; m1 <= 5; m1++) {
                for (int m2 = 0; m2 <= 9; m2++) {
                    char temp[4][5][3];
                    int valid = 1;
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 3; j++) {
                            temp[0][i][j] = digits5x3[h1][i][j];
                            temp[1][i][j] = digits5x3[h2][i][j];
                            temp[2][i][j] = digits5x3[m1][i][j];
                            temp[3][i][j] = digits5x3[m2][i][j];
                            if (input[0][i][j] == '#' && temp[0][i][j] != '#') valid = 0;
                            if (input[1][i][j] == '#' && temp[1][i][j] != '#') valid = 0;
                            if (input[2][i][j] == '#' && temp[2][i][j] != '#') valid = 0;
                            if (input[3][i][j] == '#' && temp[3][i][j] != '#') valid = 0;
                        }
                    }
                    if (valid) {
                        if (h1 < min_h1) {
                            min_h1 = h1;
                            min_h2 = h2;
                            min_m1 = m1;
                            min_m2 = m2;
                        } else if (h1 == min_h1 && h2 < min_h2) {
                            min_h2 = h2;
                            min_m1 = m1;
                            min_m2 = m2;
                        } else if (h1 == min_h1 && h2 == min_h2 && m1 < min_m1) {
                            min_m1 = m1;
                            min_m2 = m2;
                        } else if (h1 == min_h1 && h2 == min_h2 && m1 == min_m1 && m2 < min_m2) {
                            min_m2 = m2;
                        }
                    }
                }
            }
        }
    }

    printf("%d%d:%d%d\n", min_h1, min_h2, min_m1, min_m2);

    return 0;
}
