#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main() {
    int x;
    char buffer[BUFFER_SIZE];
    read(0, buffer, BUFFER_SIZE);
    x = atoi(buffer);

    unsigned i = 1, j = 1, answer_len = 0;
    long long j_squared = 1, i_squared = 1;

    while (j <= 100000 && i <= 100000) {
        long long diff = j_squared - i_squared;

        if (diff < x) {
            j++;
            j_squared = (long long)j * j;
        } else if (diff == x) {
            char output_buffer[16];
            int output_len = sprintf(output_buffer, "%u\n", j);
            write(1, output_buffer, output_len);
            answer_len++;
            j++;
            j_squared = (long long)j * j;
        } else {
            i++;
            i_squared = (long long)i * i;
        }
    }

    if (answer_len == 0) {
        write(1, "-1\n", 3);
    }

    return 0;
}